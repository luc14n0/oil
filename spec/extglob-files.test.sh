# Extended globs are an OPTION in bash, but not mksh (because the feature
# originated in ksh).
#
# However all extended globs are syntax errors if shopt -s extglob isn't set.
# In Oil, they are not PARSE TIME errors, but the syntax won't be respected at
# RUNTIME, i.e. when passed to fnmatch().
#
# GNU libc has the FNM_EXTMATCH extension to fnmatch().  (I don't think musl
# libc has it.)  However, this came after all popular shells were implemented!
# I don't think any shell uses it, but we're taking advantage of it.
#
# Extended glob syntax is ugly, but I guess it's handy because it's similar to
# *.[ch]... but the extensions can be different length: *.@(cc|h)
# It's also used for negation like
#
#   cp !(_*) /tmp
#
# I tend to use 'find', but this is a shorter syntax.

# From the bash manual:

# "In addition to the traditional globs (supported by all Bourne-family shells)
# that we've seen so far, Bash (and Korn Shell) offers extended globs, which
# have the expressive power of regular expressions. Korn shell enables these by
# default; in Bash, you must run the command "

# ?(pattern-list): Matches empty or one of the patterns
# *(pattern-list): Matches empty or any number of occurrences of the patterns
# +(pattern-list): Matches at least one occurrences of the patterns
# @(pattern-list): Matches exactly one of the patterns
# !(pattern-list): Matches anything EXCEPT any of the patterns

#### @() matches exactly one of the patterns
shopt -s extglob
mkdir -p 0
cd 0
touch {foo,bar}.cc {foo,bar,baz}.h
echo @(*.cc|*.h)
## stdout: bar.cc bar.h baz.h foo.cc foo.h

#### ?() matches 0 or 1
shopt -s extglob
mkdir -p 1
cd 1
touch {foo,bar}.cc {foo,bar,baz}.h foo. foo.hh
echo foo.?(cc|h)
## stdout: foo. foo.cc foo.h

#### *() matches 0 or more
shopt -s extglob
mkdir -p eg1
touch eg1/_ eg1/_One eg1/_OneOne eg1/_TwoTwo eg1/_OneTwo
echo eg1/_*(One|Two)
## stdout: eg1/_ eg1/_One eg1/_OneOne eg1/_OneTwo eg1/_TwoTwo

#### +() matches 1 or more
shopt -s extglob
mkdir -p eg2
touch eg2/_ eg2/_One eg2/_OneOne eg2/_TwoTwo eg2/_OneTwo
echo eg2/_+(One|Two)
## stdout: eg2/_One eg2/_OneOne eg2/_OneTwo eg2/_TwoTwo

#### !(*.h|*.cc) to match everything except C++
shopt -s extglob
mkdir -p extglob2
touch extglob2/{foo,bar}.cc extglob2/{foo,bar,baz}.h \
      extglob2/{foo,bar,baz}.py
echo extglob2/!(*.h|*.cc)
## stdout: extglob2/bar.py extglob2/baz.py extglob2/foo.py

#### Two adjacent alternations
shopt -s extglob
mkdir -p 2
touch 2/{aa,ab,ac,ba,bb,bc,ca,cb,cc}
echo 2/!(b)@(b|c)
echo 2/!(b)?@(b|c)  # wildcard in between
echo 2/!(b)a@(b|c)  # constant in between
## STDOUT:
2/ab 2/ac 2/cb 2/cc
2/ab 2/ac 2/bb 2/bc 2/cb 2/cc
2/ab 2/ac
## END

#### Nested extended glob pattern 
shopt -s extglob
mkdir -p eg6
touch eg6/{ab,ac,ad,az,bc,bd}
echo eg6/a@(!(c|d))
echo eg6/a!(@(ab|b*))
## STDOUT:
eg6/ab eg6/az
eg6/ac eg6/ad eg6/az
## END

#### Extended glob patterns with spaces
shopt -s extglob
mkdir -p eg4
touch eg4/a 'eg4/a b' eg4/foo
argv.py eg4/@(a b|foo)
## STDOUT:
['eg4/a b', 'eg4/foo']
## END

#### Filenames with spaces
shopt -s extglob
mkdir -p eg5
touch eg5/'a b'{cd,de,ef}
argv.py eg5/'a '@(bcd|bde|zzz)
## STDOUT:
['eg5/a bcd', 'eg5/a bde']
## END

#### nullglob with extended glob
shopt -s extglob
mkdir eg6
argv.py eg6/@(no|matches)  # no matches
shopt -s nullglob  # test this too
argv.py eg6/@(no|matches)  # no matches
## STDOUT:
['eg6/@(no|matches)']
[]
## END
## BUG mksh STDOUT:
['eg6/@(no|matches)']
['eg6/@(no|matches)']
## END

#### glob other punctuation chars (lexer mode)
# mksh sorts them differently
shopt -s extglob
mkdir -p eg5
cd eg5
touch __{'<>','{}','|','#','&&'}
argv.py @('__<>'|__{}|__\||__#|__&&)
## stdout: ['__<>', '__|', '__{}', '__&&', '__#']
## OK mksh stdout: ['__#', '__&&', '__<>', '__{}', '__|']

#### dynamic extglob from variable

# mksh does static parsing so it doesn't like this?
shopt -s extglob
mkdir -p eg3
touch eg3/{foo,bar}
g=eg3/@(foo|bar)
echo $g "$g"  # quoting inhibits globbing
## mksh stdout: eg3/@(foo|bar) eg3/@(foo|bar)
## OK bash stdout: eg3/bar eg3/foo eg3/@(foo|bar)

#### Extended glob syntax in bad redirect context
shopt -s extglob
rm bad_*

# They actually write this literal file!  This is what EvalWordToString() does,
# as opposed to _EvalWordToParts.
echo foo > bad_@(*.cc|*.h)
echo bad_*
## STDOUT:
bad_@(*.cc|*.h)
## END

#### Extended glob as argument to ${undef:-} (dynamic globbing)

# This case popped into my mind after inspecting osh/word_eval.py for calls to
# _EvalWordToParts()

shopt -s extglob

mkdir -p eg8
cd eg8
touch {foo,bar,spam}.py

# regular glob
echo ${undef:-*.py}

# extended glob
echo ${undef:-@(foo|bar).py}

## STDOUT:
bar.py foo.py spam.py
@(foo|bar).py
## END
## OK bash STDOUT:
bar.py foo.py spam.py
bar.py foo.py
## END

#### Extended glob in assignment builtin

# Another invocation of _EvalWordToParts() that OSH should handle

shopt -s extglob
mkdir -p eg9
cd eg9
touch {foo,bar}.py
typeset -@(*.py) myvar
echo status=$?
## STDOUT:
status=2
## END
## OK mksh STDOUT:
status=1
## END
## OK osh status: 1
## OK osh STDOUT:
## END

#### Extended glob in same word as array
shopt -s extglob
mkdir -p eg10
cd eg10

touch {'a b c',bee,cee}.{py,cc}
set -- 'a b' 'c'

argv.py "$@"

# This works!
argv.py star glob "$*"*.py
argv.py star extglob "$*"*@(.py|cc)

# Hm this actually still works!  the first two parts are literal.  And then
# there's something like the simple_word_eval algorithm on the rest.  Gah.
argv.py at extglob "$@"*@(.py|cc)

## STDOUT:
['a b', 'c']
['star', 'glob', 'a b c.py']
['star', 'extglob', 'a b c.cc', 'a b c.py']
['at', 'extglob', 'a b', 'cee.cc', 'cee.py']
## END
## N-I osh STDOUT:
['a b', 'c']
['star', 'glob', 'a b c.py']
['star', 'extglob', 'a b c.cc', 'a b c.py']
## END
## N-I osh status: 1

#### Extended glob with word splitting
shopt -s extglob
mkdir -p 3
cd 3

x='a b'
touch bar.{cc,h}

# OSH may disallow splitting when there's an extended glob
argv.py $x*.@(cc|h)

## STDOUT:
['a', 'bar.cc', 'bar.h']
## END
## N-I osh STDOUT:
['a b*.@(cc|h)']
## END

#### In Array Literal and for loop
shopt -s extglob
mkdir -p eg11
cd eg11
touch {foo,bar,spam}.py
for x in @(fo*|bar).py; do
  echo $x
done

echo ---
declare -a A
A=(zzz @(fo*|bar).py)
echo "${A[@]}"
## STDOUT:
bar.py
foo.py
---
zzz bar.py foo.py
## END

#### No extended glob with simple_word_eval (Oil evaluation)
shopt -s oil:all
shopt -s extglob
mkdir -p eg12
cd eg12
touch {foo,bar,spam}.py
builtin write -- x@(fo*|bar).py
builtin write -- @(fo*|bar).py
## status: 1
## STDOUT:
## END
