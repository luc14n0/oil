// prebuilt/asdl/runtime.mycpp.cc: GENERATED by mycpp

#include "prebuilt/asdl/runtime.mycpp.h"
// BEGIN mycpp output

#include "mycpp/runtime.h"

GLOBAL_STR(str0, "(");
GLOBAL_STR(str1, ")");
GLOBAL_STR(str2, "_");
GLOBAL_STR(str3, "T");
GLOBAL_STR(str4, "F");
GLOBAL_STR(str5, "\n<html>\n  <head>\n     <title>oil AST</title>\n     <style>\n      .n { color: brown }\n      .s { font-weight: bold }\n      .o { color: darkgreen }\n     </style>\n  </head>\n  <body>\n    <pre>\n");
GLOBAL_STR(str6, "\n    </pre>\n  </body>\n</html>\n    ");
GLOBAL_STR(str7, "n");
GLOBAL_STR(str8, "s");
GLOBAL_STR(str9, "o");
GLOBAL_STR(str10, "o");
GLOBAL_STR(str11, "o");
GLOBAL_STR(str12, "<span class=\"%s\">");
GLOBAL_STR(str13, "</span>");
GLOBAL_STR(str14, " ");
GLOBAL_STR(str15, "\n");
GLOBAL_STR(str16, " ");
GLOBAL_STR(str17, "]");
GLOBAL_STR(str18, " ");
GLOBAL_STR(str19, " ");
GLOBAL_STR(str20, "\n");
GLOBAL_STR(str21, "\n");
GLOBAL_STR(str22, " ");
GLOBAL_STR(str23, "%s%s: [");
GLOBAL_STR(str24, "\n");
GLOBAL_STR(str25, "\n");
GLOBAL_STR(str26, "%s]");
GLOBAL_STR(str27, "%s%s: ");
GLOBAL_STR(str28, "\n");
GLOBAL_STR(str29, "\n");
GLOBAL_STR(str30, " ");
GLOBAL_STR(str31, "UNTYPED any");
GLOBAL_STR(str32, " ");
GLOBAL_STR(str33, " ");
GLOBAL_STR(str34, " %s:");
GLOBAL_STR(str35, "UNTYPED any");
GLOBAL_STR(str36, "[");
GLOBAL_STR(str37, " ");
GLOBAL_STR(str38, "]");
GLOBAL_STR(str39, "\u001b[0;0m");
GLOBAL_STR(str40, "\u001b[1m");
GLOBAL_STR(str41, "\u001b[4m");
GLOBAL_STR(str42, "\u001b[7m");
GLOBAL_STR(str43, "\u001b[31m");
GLOBAL_STR(str44, "\u001b[32m");
GLOBAL_STR(str45, "\u001b[33m");
GLOBAL_STR(str46, "\u001b[34m");
GLOBAL_STR(str47, "&");
GLOBAL_STR(str48, "&amp;");
GLOBAL_STR(str49, "<");
GLOBAL_STR(str50, "&lt;");
GLOBAL_STR(str51, ">");
GLOBAL_STR(str52, "&gt;");
GLOBAL_STR(str53, "\\'\r\n\t\u0000");
GLOBAL_STR(str54, "$'");
GLOBAL_STR(str55, "'");
GLOBAL_STR(str56, "'");
GLOBAL_STR(str57, "");
GLOBAL_STR(str58, "'");
GLOBAL_STR(str59, "'");
GLOBAL_STR(str60, "");
GLOBAL_STR(str61, "'");
GLOBAL_STR(str62, "'");
GLOBAL_STR(str63, "");
GLOBAL_STR(str64, "\\");
GLOBAL_STR(str65, "\\\\");
GLOBAL_STR(str66, "'");
GLOBAL_STR(str67, "\\'");
GLOBAL_STR(str68, "\n");
GLOBAL_STR(str69, "\\n");
GLOBAL_STR(str70, "\r");
GLOBAL_STR(str71, "\\r");
GLOBAL_STR(str72, "\t");
GLOBAL_STR(str73, "\\t");
GLOBAL_STR(str74, "\u0000");
GLOBAL_STR(str75, "\\x00");
GLOBAL_STR(str76, "\\0");
GLOBAL_STR(str77, "");
GLOBAL_STR(str78, "");
GLOBAL_STR(str79, "");
GLOBAL_STR(str80, "\\");
GLOBAL_STR(str81, "\\\\");
GLOBAL_STR(str82, "'");
GLOBAL_STR(str83, "\\'");
GLOBAL_STR(str84, "\n");
GLOBAL_STR(str85, "\\n");
GLOBAL_STR(str86, "\r");
GLOBAL_STR(str87, "\\r");
GLOBAL_STR(str88, "\t");
GLOBAL_STR(str89, "\\t");
GLOBAL_STR(str90, "\u0000");
GLOBAL_STR(str91, "\\x00");
GLOBAL_STR(str92, "\\0");

namespace ansi {  // forward declare


}  // forward declare namespace ansi

namespace cgi {  // forward declare


}  // forward declare namespace cgi

namespace qsn {  // forward declare


}  // forward declare namespace qsn

namespace ansi {  // declare

extern Str* RESET;
extern Str* BOLD;
extern Str* UNDERLINE;
extern Str* REVERSE;
extern Str* RED;
extern Str* GREEN;
extern Str* YELLOW;
extern Str* BLUE;


}  // declare namespace ansi

namespace cgi {  // declare

Str* escape(Str* s);


}  // declare namespace cgi

namespace qsn {  // declare

extern int BIT8_UTF8;
extern int BIT8_U_ESCAPE;
extern int BIT8_X_ESCAPE;
extern int MUST_QUOTE;
bool _encode(Str* s, int bit8_display, bool shell_compat, List<Str*>* parts);
Str* maybe_shell_encode(Str* s, int flags = 0);
Str* maybe_encode(Str* s, int bit8_display = BIT8_UTF8);
Str* encode(Str* s, int bit8_display = BIT8_UTF8);
void _encode_bytes_x(Str* s, bool shell_compat, List<Str*>* parts);
extern int Ascii;
extern int Begin2;
extern int Begin3;
extern int Begin4;
extern int Cont;
extern int Invalid;
extern int Start;
extern int B2_1;
extern int B3_1;
extern int B4_1;
extern int B3_2;
extern int B4_2;
extern int B4_3;
bool _encode_runes(Str* s, int bit8_display, bool shell_compat, List<Str*>* parts);
Str* maybe_qtt_encode(Str* s, int bit8_display);


}  // declare namespace qsn

namespace runtime {  // define

using hnode_asdl::hnode;
using hnode_asdl::color_t;
using hnode_asdl::color_e;
int NO_SPID = -1;

hnode::Record* NewRecord(Str* node_type) {
  StackRoots _roots({&node_type});

  return Alloc<hnode::Record>(node_type, Alloc<List<hnode_asdl::Field*>>(), false, str0, str1, Alloc<List<hnode_asdl::hnode_t*>>());
}

hnode::Leaf* NewLeaf(Str* s, hnode_asdl::color_t e_color) {
  StackRoots _roots({&s});

  if (s == nullptr) {
    return Alloc<hnode::Leaf>(str2, color_e::OtherConst);
  }
  else {
    return Alloc<hnode::Leaf>(s, e_color);
  }
}
Str* TRUE_STR = str3;
Str* FALSE_STR = str4;

}  // define namespace runtime

namespace format {  // define

using hnode_asdl::hnode;
using hnode_asdl::hnode_e;
using hnode_asdl::hnode_t;
using hnode_asdl::color_e;
using hnode_asdl::color_t;

format::ColorOutput* DetectConsoleOutput(mylib::Writer* f) {
  StackRoots _roots({&f});

  if (f->isatty()) {
    return Alloc<AnsiOutput>(f);
  }
  else {
    return Alloc<TextOutput>(f);
  }
}

ColorOutput::ColorOutput(mylib::Writer* f) {
  this->f = f;
  this->num_chars = 0;
}

format::ColorOutput* ColorOutput::NewTempBuffer() {
  FAIL(kNotImplemented);  // Python NotImplementedError
}

void ColorOutput::FileHeader() {
  ;  // pass
}

void ColorOutput::FileFooter() {
  ;  // pass
}

void ColorOutput::PushColor(hnode_asdl::color_t e_color) {
  FAIL(kNotImplemented);  // Python NotImplementedError
}

void ColorOutput::PopColor() {
  FAIL(kNotImplemented);  // Python NotImplementedError
}

void ColorOutput::write(Str* s) {
  StackRoots _roots({&s});

  this->f->write(s);
  this->num_chars += len(s);
}

void ColorOutput::WriteRaw(Tuple2<Str*, int>* raw) {
  Str* s = nullptr;
  int num_chars;
  StackRoots _roots({&raw, &s});

  Tuple2<Str*, int>* tup0 = raw;
  s = tup0->at0();
  num_chars = tup0->at1();
  this->f->write(s);
  this->num_chars += num_chars;
}

int ColorOutput::NumChars() {
  return this->num_chars;
}

Tuple2<Str*, int> ColorOutput::GetRaw() {
  mylib::BufWriter* f = static_cast<mylib::BufWriter*>(this->f);
  return Tuple2<Str*, int>(f->getvalue(), this->num_chars);
}

TextOutput::TextOutput(mylib::Writer* f) : ColorOutput(f) {
}

format::TextOutput* TextOutput::NewTempBuffer() {
  return Alloc<TextOutput>(Alloc<mylib::BufWriter>());
}

void TextOutput::PushColor(hnode_asdl::color_t e_color) {
  ;  // pass
}

void TextOutput::PopColor() {
  ;  // pass
}

HtmlOutput::HtmlOutput(mylib::Writer* f) : ColorOutput(f) {
}

format::HtmlOutput* HtmlOutput::NewTempBuffer() {
  return Alloc<HtmlOutput>(Alloc<mylib::BufWriter>());
}

void HtmlOutput::FileHeader() {
  this->f->write(str5);
}

void HtmlOutput::FileFooter() {
  this->f->write(str6);
}

void HtmlOutput::PushColor(hnode_asdl::color_t e_color) {
  Str* css_class = nullptr;
  StackRoots _roots({&css_class});

  if (e_color == color_e::TypeName) {
    css_class = str7;
  }
  else {
    if (e_color == color_e::StringConst) {
      css_class = str8;
    }
    else {
      if (e_color == color_e::OtherConst) {
        css_class = str9;
      }
      else {
        if (e_color == color_e::External) {
          css_class = str10;
        }
        else {
          if (e_color == color_e::UserType) {
            css_class = str11;
          }
          else {
            assert(0);  // AssertionError
          }
        }
      }
    }
  }
  this->f->write(StrFormat("<span class=\"%s\">", css_class));
}

void HtmlOutput::PopColor() {
  this->f->write(str13);
}

void HtmlOutput::write(Str* s) {
  StackRoots _roots({&s});

  this->f->write(cgi::escape(s));
  this->num_chars += len(s);
}

AnsiOutput::AnsiOutput(mylib::Writer* f) : ColorOutput(f) {
}

format::AnsiOutput* AnsiOutput::NewTempBuffer() {
  return Alloc<AnsiOutput>(Alloc<mylib::BufWriter>());
}

void AnsiOutput::PushColor(hnode_asdl::color_t e_color) {
  if (e_color == color_e::TypeName) {
    this->f->write(ansi::YELLOW);
  }
  else {
    if (e_color == color_e::StringConst) {
      this->f->write(ansi::BOLD);
    }
    else {
      if (e_color == color_e::OtherConst) {
        this->f->write(ansi::GREEN);
      }
      else {
        if (e_color == color_e::External) {
          this->f->write(str_concat(ansi::BOLD, ansi::BLUE));
        }
        else {
          if (e_color == color_e::UserType) {
            this->f->write(ansi::GREEN);
          }
          else {
            assert(0);  // AssertionError
          }
        }
      }
    }
  }
}

void AnsiOutput::PopColor() {
  this->f->write(ansi::RESET);
}
int INDENT = 2;

_PrettyPrinter::_PrettyPrinter(int max_col) {
  this->max_col = max_col;
}

bool _PrettyPrinter::_PrintWrappedArray(List<hnode_asdl::hnode_t*>* array, int prefix_len, format::ColorOutput* f, int indent) {
  bool all_fit;
  int chars_so_far;
  int i;
  format::ColorOutput* single_f = nullptr;
  Str* s = nullptr;
  int num_chars;
  StackRoots _roots({&array, &f, &single_f, &s});

  all_fit = true;
  chars_so_far = prefix_len;
  i = 0;
  for (ListIter<hnode_asdl::hnode_t*> it(array); !it.Done(); it.Next(), ++i) {
    hnode_asdl::hnode_t* val = it.Value();
    StackRoots _for({&val  });
    if (i != 0) {
      f->write(str14);
    }
    single_f = f->NewTempBuffer();
    if (_TrySingleLine(val, single_f, (this->max_col - chars_so_far))) {
      Tuple2<Str*, int> tup1 = single_f->GetRaw();
      s = tup1.at0();
      num_chars = tup1.at1();
      f->WriteRaw((Alloc<Tuple2<Str*, int>>(s, num_chars)));
      chars_so_far += single_f->NumChars();
    }
    else {
      f->write(str15);
      this->PrintNode(val, f, (indent + INDENT));
      chars_so_far = 0;
      all_fit = false;
    }
  }
  return all_fit;
}

bool _PrettyPrinter::_PrintWholeArray(List<hnode_asdl::hnode_t*>* array, int prefix_len, format::ColorOutput* f, int indent) {
  bool all_fit;
  List<Tuple2<Str*, int>*>* pieces = nullptr;
  int chars_so_far;
  format::ColorOutput* single_f = nullptr;
  Str* s = nullptr;
  int num_chars;
  int i;
  StackRoots _roots({&array, &f, &pieces, &single_f, &s});

  all_fit = true;
  pieces = Alloc<List<Tuple2<Str*, int>*>>();
  chars_so_far = prefix_len;
  for (ListIter<hnode_asdl::hnode_t*> it(array); !it.Done(); it.Next()) {
    hnode_asdl::hnode_t* item = it.Value();
    StackRoots _for({&item  });
    single_f = f->NewTempBuffer();
    if (_TrySingleLine(item, single_f, (this->max_col - chars_so_far))) {
      Tuple2<Str*, int> tup2 = single_f->GetRaw();
      s = tup2.at0();
      num_chars = tup2.at1();
      pieces->append((Alloc<Tuple2<Str*, int>>(s, num_chars)));
      chars_so_far += single_f->NumChars();
    }
    else {
      all_fit = false;
      break;
    }
  }
  if (all_fit) {
    i = 0;
    for (ListIter<Tuple2<Str*, int>*> it(pieces); !it.Done(); it.Next(), ++i) {
      Tuple2<Str*, int>* p = it.Value();
      StackRoots _for({&p    });
      if (i != 0) {
        f->write(str16);
      }
      f->WriteRaw(p);
    }
    f->write(str17);
  }
  return all_fit;
}

void _PrettyPrinter::_PrintRecord(hnode::Record* node, format::ColorOutput* f, int indent) {
  Str* ind = nullptr;
  Str* prefix = nullptr;
  int prefix_len;
  bool all_fit;
  Str* name = nullptr;
  hnode_asdl::hnode_t* val = nullptr;
  Str* ind1 = nullptr;
  hnode_asdl::hnode_t* UP_val = nullptr;
  int tag;
  Str* name_str = nullptr;
  format::ColorOutput* single_f = nullptr;
  Str* s = nullptr;
  int num_chars;
  StackRoots _roots({&node, &f, &ind, &prefix, &name, &val, &ind1, &UP_val, &name_str, &single_f, &s});

  ind = str_repeat(str18, indent);
  if (node->abbrev) {
    prefix = str_concat(ind, node->left);
    f->write(prefix);
    if (len(node->node_type)) {
      f->PushColor(color_e::TypeName);
      f->write(node->node_type);
      f->PopColor();
      f->write(str19);
    }
    prefix_len = ((len(prefix) + len(node->node_type)) + 1);
    all_fit = this->_PrintWrappedArray(node->unnamed_fields, prefix_len, f, indent);
    if (!all_fit) {
      f->write(str20);
      f->write(ind);
    }
    f->write(node->right);
  }
  else {
    f->write(str_concat(ind, node->left));
    f->PushColor(color_e::TypeName);
    f->write(node->node_type);
    f->PopColor();
    f->write(str21);
    for (ListIter<hnode_asdl::Field*> it(node->fields); !it.Done(); it.Next()) {
      hnode_asdl::Field* field = it.Value();
      StackRoots _for({&field    });
      name = field->name;
      val = field->val;
      ind1 = str_repeat(str22, (indent + INDENT));
      UP_val = val;
      tag = val->tag();
      if (tag == hnode_e::Array) {
        hnode::Array* val = static_cast<hnode::Array*>(UP_val);
        name_str = StrFormat("%s%s: [", ind1, name);
        f->write(name_str);
        prefix_len = len(name_str);
        if (!this->_PrintWholeArray(val->children, prefix_len, f, indent)) {
          f->write(str24);
          for (ListIter<hnode_asdl::hnode_t*> it(val->children); !it.Done(); it.Next()) {
            hnode_asdl::hnode_t* child = it.Value();
            StackRoots _for({&child          });
            this->PrintNode(child, f, ((indent + INDENT) + INDENT));
            f->write(str25);
          }
          f->write(StrFormat("%s]", ind1));
        }
      }
      else {
        name_str = StrFormat("%s%s: ", ind1, name);
        f->write(name_str);
        prefix_len = len(name_str);
        single_f = f->NewTempBuffer();
        if (_TrySingleLine(val, single_f, (this->max_col - prefix_len))) {
          Tuple2<Str*, int> tup3 = single_f->GetRaw();
          s = tup3.at0();
          num_chars = tup3.at1();
          f->WriteRaw((Alloc<Tuple2<Str*, int>>(s, num_chars)));
        }
        else {
          f->write(str28);
          this->PrintNode(val, f, ((indent + INDENT) + INDENT));
        }
      }
      f->write(str29);
    }
    f->write(str_concat(ind, node->right));
  }
}

void _PrettyPrinter::PrintNode(hnode_asdl::hnode_t* node, format::ColorOutput* f, int indent) {
  Str* ind = nullptr;
  format::ColorOutput* single_f = nullptr;
  Str* s = nullptr;
  int num_chars;
  hnode_asdl::hnode_t* UP_node = nullptr;
  int tag;
  StackRoots _roots({&node, &f, &ind, &single_f, &s, &UP_node});

  ind = str_repeat(str30, indent);
  single_f = f->NewTempBuffer();
  single_f->write(ind);
  if (_TrySingleLine(node, single_f, (this->max_col - indent))) {
    Tuple2<Str*, int> tup4 = single_f->GetRaw();
    s = tup4.at0();
    num_chars = tup4.at1();
    f->WriteRaw((Alloc<Tuple2<Str*, int>>(s, num_chars)));
    return ;
  }
  UP_node = node;
  tag = node->tag();
  if (tag == hnode_e::Leaf) {
    hnode::Leaf* node = static_cast<hnode::Leaf*>(UP_node);
    f->PushColor(node->color);
    f->write(qsn::maybe_encode(node->s));
    f->PopColor();
  }
  else {
    if (tag == hnode_e::External) {
      hnode::External* node = static_cast<hnode::External*>(UP_node);
      f->PushColor(color_e::External);
      // if not PYTHON
      {
        f->write(str31);
      }
      // endif MYCPP
      f->PopColor();
    }
    else {
      if (tag == hnode_e::Record) {
        hnode::Record* node = static_cast<hnode::Record*>(UP_node);
        this->_PrintRecord(node, f, indent);
      }
      else {
        assert(0);  // AssertionError
      }
    }
  }
}

bool _TrySingleLineObj(hnode::Record* node, format::ColorOutput* f, int max_chars) {
  int i;
  StackRoots _roots({&node, &f});

  f->write(node->left);
  if (node->abbrev) {
    if (len(node->node_type)) {
      f->PushColor(color_e::TypeName);
      f->write(node->node_type);
      f->PopColor();
      f->write(str32);
    }
    i = 0;
    for (ListIter<hnode_asdl::hnode_t*> it(node->unnamed_fields); !it.Done(); it.Next(), ++i) {
      hnode_asdl::hnode_t* val = it.Value();
      StackRoots _for({&val    });
      if (i != 0) {
        f->write(str33);
      }
      if (!_TrySingleLine(val, f, max_chars)) {
        return false;
      }
    }
  }
  else {
    f->PushColor(color_e::TypeName);
    f->write(node->node_type);
    f->PopColor();
    for (ListIter<hnode_asdl::Field*> it(node->fields); !it.Done(); it.Next()) {
      hnode_asdl::Field* field = it.Value();
      StackRoots _for({&field    });
      f->write(StrFormat(" %s:", field->name));
      if (!_TrySingleLine(field->val, f, max_chars)) {
        return false;
      }
    }
  }
  f->write(node->right);
  return true;
}

bool _TrySingleLine(hnode_asdl::hnode_t* node, format::ColorOutput* f, int max_chars) {
  hnode_asdl::hnode_t* UP_node = nullptr;
  int tag;
  int i;
  int num_chars_so_far;
  StackRoots _roots({&node, &f, &UP_node});

  UP_node = node;
  tag = node->tag();
  if (tag == hnode_e::Leaf) {
    hnode::Leaf* node = static_cast<hnode::Leaf*>(UP_node);
    f->PushColor(node->color);
    f->write(qsn::maybe_encode(node->s));
    f->PopColor();
  }
  else {
    if (tag == hnode_e::External) {
      hnode::External* node = static_cast<hnode::External*>(UP_node);
      f->PushColor(color_e::External);
      // if not PYTHON
      {
        f->write(str35);
      }
      // endif MYCPP
      f->PopColor();
    }
    else {
      if (tag == hnode_e::Array) {
        hnode::Array* node = static_cast<hnode::Array*>(UP_node);
        f->write(str36);
        i = 0;
        for (ListIter<hnode_asdl::hnode_t*> it(node->children); !it.Done(); it.Next(), ++i) {
          hnode_asdl::hnode_t* item = it.Value();
          StackRoots _for({&item        });
          if (i != 0) {
            f->write(str37);
          }
          if (!_TrySingleLine(item, f, max_chars)) {
            return false;
          }
        }
        f->write(str38);
      }
      else {
        if (tag == hnode_e::Record) {
          hnode::Record* node = static_cast<hnode::Record*>(UP_node);
          return _TrySingleLineObj(node, f, max_chars);
        }
        else {
          assert(0);  // AssertionError
        }
      }
    }
  }
  num_chars_so_far = f->NumChars();
  if (num_chars_so_far > max_chars) {
    return false;
  }
  return true;
}

void PrintTree(hnode_asdl::hnode_t* node, format::ColorOutput* f) {
  format::_PrettyPrinter* pp = nullptr;
  StackRoots _roots({&node, &f, &pp});

  pp = Alloc<_PrettyPrinter>(100);
  pp->PrintNode(node, f, 0);
}

}  // define namespace format

namespace ansi {  // define

Str* RESET = str39;
Str* BOLD = str40;
Str* UNDERLINE = str41;
Str* REVERSE = str42;
Str* RED = str43;
Str* GREEN = str44;
Str* YELLOW = str45;
Str* BLUE = str46;

}  // define namespace ansi

namespace cgi {  // define


Str* escape(Str* s) {
  StackRoots _roots({&s});

  s = s->replace(str47, str48);
  s = s->replace(str49, str50);
  s = s->replace(str51, str52);
  return s;
}

}  // define namespace cgi

namespace qsn {  // define

int BIT8_UTF8 = 0;
int BIT8_U_ESCAPE = 1;
int BIT8_X_ESCAPE = 2;
int MUST_QUOTE = 4;

bool _encode(Str* s, int bit8_display, bool shell_compat, List<Str*>* parts) {
  StackRoots _roots({&s, &parts});

  if (bit8_display == BIT8_X_ESCAPE) {
    _encode_bytes_x(s, shell_compat, parts);
    return true;
  }
  else {
    return _encode_runes(s, bit8_display, shell_compat, parts);
  }
}

Str* maybe_shell_encode(Str* s, int flags) {
  int quote;
  int must_quote;
  int bit8_display;
  List<Str*>* parts = nullptr;
  bool valid_utf8;
  Str* prefix = nullptr;
  StackRoots _roots({&s, &parts, &prefix});

  quote = 0;
  must_quote = (flags & 4);
  bit8_display = (flags & 3);
  if (len(s) == 0) {
    quote = 1;
  }
  else {
    for (StrIter it(s); !it.Done(); it.Next()) {
      Str* ch = it.Value();
      StackRoots _for({&ch    });
      if ((!must_quote and IsPlainChar(ch))) {
        continue;
      }
      quote = 1;
      if ((str_contains(str53, ch) or IsUnprintableLow(ch))) {
        quote = 2;
        break;
      }
    }
  }
  if (quote == 0) {
    return s;
  }
  parts = Alloc<List<Str*>>();
  valid_utf8 = _encode(s, bit8_display, true, parts);
  if ((!valid_utf8 or quote == 2)) {
    prefix = str54;
  }
  else {
    prefix = str55;
  }
  parts->append(str56);
  return str_concat(prefix, str57->join(parts));
}

Str* maybe_encode(Str* s, int bit8_display) {
  int quote;
  List<Str*>* parts = nullptr;
  StackRoots _roots({&s, &parts});

  quote = 0;
  if (len(s) == 0) {
    quote = 1;
  }
  else {
    for (StrIter it(s); !it.Done(); it.Next()) {
      Str* ch = it.Value();
      StackRoots _for({&ch    });
      if (IsPlainChar(ch)) {
        continue;
      }
      quote = 1;
    }
  }
  if (!quote) {
    return s;
  }
  parts = Alloc<List<Str*>>();
  parts->append(str58);
  _encode(s, bit8_display, false, parts);
  parts->append(str59);
  return str60->join(parts);
}

Str* encode(Str* s, int bit8_display) {
  List<Str*>* parts = nullptr;
  StackRoots _roots({&s, &parts});

  parts = Alloc<List<Str*>>();
  parts->append(str61);
  _encode(s, bit8_display, false, parts);
  parts->append(str62);
  return str63->join(parts);
}

void _encode_bytes_x(Str* s, bool shell_compat, List<Str*>* parts) {
  Str* part = nullptr;
  StackRoots _roots({&s, &parts, &part});

  for (StrIter it(s); !it.Done(); it.Next()) {
    Str* byte = it.Value();
    StackRoots _for({&byte  });
    if (str_equals(byte, str64)) {
      part = str65;
    }
    else {
      if (str_equals(byte, str66)) {
        part = str67;
      }
      else {
        if (str_equals(byte, str68)) {
          part = str69;
        }
        else {
          if (str_equals(byte, str70)) {
            part = str71;
          }
          else {
            if (str_equals(byte, str72)) {
              part = str73;
            }
            else {
              if (str_equals(byte, str74)) {
                part = shell_compat ? str75 : str76;
              }
              else {
                if (IsUnprintableLow(byte)) {
                  part = XEscape(byte);
                }
                else {
                  if (IsUnprintableHigh(byte)) {
                    part = XEscape(byte);
                  }
                  else {
                    part = byte;
                  }
                }
              }
            }
          }
        }
      }
    }
    parts->append(part);
  }
}
int Ascii = 0;
int Begin2 = 1;
int Begin3 = 2;
int Begin4 = 3;
int Cont = 4;
int Invalid = 5;
int Start = 0;
int B2_1 = 1;
int B3_1 = 2;
int B4_1 = 3;
int B3_2 = 4;
int B4_2 = 5;
int B4_3 = 6;

bool _encode_runes(Str* s, int bit8_display, bool shell_compat, List<Str*>* parts) {
  bool valid_utf8;
  int state;
  Str* r1 = nullptr;
  Str* r2 = nullptr;
  Str* r3 = nullptr;
  int b;
  int typ;
  Str* out = nullptr;
  int rune;
  StackRoots _roots({&s, &parts, &r1, &r2, &r3, &out});

  valid_utf8 = true;
  state = Start;
  r1 = str77;
  r2 = str78;
  r3 = str79;
  for (StrIter it(s); !it.Done(); it.Next()) {
    Str* byte = it.Value();
    StackRoots _for({&byte  });
    b = ord(byte);
    if (b < 127) {
      typ = Ascii;
    }
    else {
      if ((b >> 6) == 2) {
        typ = Cont;
      }
      else {
        if ((b >> 5) == 6) {
          typ = Begin2;
        }
        else {
          if ((b >> 4) == 14) {
            typ = Begin3;
          }
          else {
            if ((b >> 3) == 30) {
              typ = Begin4;
            }
            else {
              typ = Invalid;
            }
          }
        }
      }
    }
    if (typ != Cont) {
      if (state >= B2_1) {
        valid_utf8 = false;
        parts->append(XEscape(r1));
      }
      if (state >= B3_2) {
        parts->append(XEscape(r2));
      }
      if (state >= B4_3) {
        parts->append(XEscape(r3));
      }
    }
    if (typ == Ascii) {
      state = Start;
      if (str_equals(byte, str80)) {
        out = str81;
      }
      else {
        if (str_equals(byte, str82)) {
          out = str83;
        }
        else {
          if (str_equals(byte, str84)) {
            out = str85;
          }
          else {
            if (str_equals(byte, str86)) {
              out = str87;
            }
            else {
              if (str_equals(byte, str88)) {
                out = str89;
              }
              else {
                if (str_equals(byte, str90)) {
                  out = shell_compat ? str91 : str92;
                }
                else {
                  if (IsUnprintableLow(byte)) {
                    if (bit8_display == BIT8_U_ESCAPE) {
                      out = UEscape(ord(byte));
                    }
                    else {
                      out = XEscape(byte);
                    }
                  }
                  else {
                    out = byte;
                  }
                }
              }
            }
          }
        }
      }
      parts->append(out);
    }
    else {
      if (typ == Begin2) {
        state = B2_1;
        r1 = byte;
      }
      else {
        if (typ == Begin3) {
          state = B3_1;
          r1 = byte;
        }
        else {
          if (typ == Begin4) {
            state = B4_1;
            r1 = byte;
          }
          else {
            if (typ == Invalid) {
              state = Start;
              parts->append(XEscape(byte));
              valid_utf8 = false;
            }
            else {
              if (typ == Cont) {
                if (state == Start) {
                  parts->append(XEscape(byte));
                  valid_utf8 = false;
                }
                else {
                  if (state == B2_1) {
                    if (bit8_display == BIT8_UTF8) {
                      out = str_concat(r1, byte);
                    }
                    else {
                      rune = (ord(byte) & 63);
                      rune |= ((ord(r1) & 31) << 6);
                      out = UEscape(rune);
                    }
                    parts->append(out);
                    state = Start;
                  }
                  else {
                    if (state == B3_1) {
                      r2 = byte;
                      state = B3_2;
                    }
                    else {
                      if (state == B3_2) {
                        if (bit8_display == BIT8_UTF8) {
                          out = str_concat(str_concat(r1, r2), byte);
                        }
                        else {
                          rune = (ord(byte) & 63);
                          rune |= ((ord(r2) & 63) << 6);
                          rune |= ((ord(r1) & 15) << 12);
                          out = UEscape(rune);
                        }
                        parts->append(out);
                        state = Start;
                      }
                      else {
                        if (state == B4_1) {
                          r2 = byte;
                          state = B4_2;
                        }
                        else {
                          if (state == B4_2) {
                            r3 = byte;
                            state = B4_3;
                          }
                          else {
                            if (state == B4_3) {
                              if (bit8_display == BIT8_UTF8) {
                                out = str_concat(str_concat(str_concat(r1, r2), r3), byte);
                              }
                              else {
                                rune = (ord(byte) & 63);
                                rune |= ((ord(r3) & 63) << 6);
                                rune |= ((ord(r2) & 63) << 12);
                                rune |= ((ord(r1) & 7) << 18);
                                out = UEscape(rune);
                              }
                              parts->append(out);
                              state = Start;
                            }
                            else {
                              assert(0);  // AssertionError
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else {
                assert(0);  // AssertionError
              }
            }
          }
        }
      }
    }
  }
  if (state >= B2_1) {
    valid_utf8 = false;
    parts->append(XEscape(r1));
  }
  if (state >= B3_2) {
    parts->append(XEscape(r2));
  }
  if (state >= B4_3) {
    parts->append(XEscape(r3));
  }
  return valid_utf8;
}

Str* maybe_qtt_encode(Str* s, int bit8_display) {
  StackRoots _roots({&s});

  FAIL(kNotImplemented);  // Python NotImplementedError
}

}  // define namespace qsn

