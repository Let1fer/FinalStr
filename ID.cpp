#include "ID.hpp"
#define nd                 \
    {                      \
        str = new char[1]; \
        str[0] = 0;        \
        return;            \
    }
string arr[] = { "alignas", "alignof",
    "and", "and_eq",
    "asm", "auto",
    "bitand", "bitor",
    "bool", "break",
    "case", "catch",
    "char", "char16_t",
    "char32_t", "class",
    "compl", "const",
    "constexpr", "const_cast",
    "continue", "decltype",
    "default", "delete",
    "do", "double",
    "dynamic_cast", "else",
    "enum", "explicit",
    "export", "extern",
    "false", "float",
    "for", "friend",
    "goto", "if",
    "inline", "int",
    "long", "mutable",
    "namespace", "new",
    "noexcept", "not",
    "not_eq", "nullptr",
    "operator", "or",
    "or_eq", "private",
    "protected", "public",
    "register", "reinterpret_cast",
    "return", "short",
    "signed", "sizeof",
    "static", "static_assert",
    "static_cast", "struct",
    "switch", "template",
    "this", "thread_local",
    "throw", "true",
    "try", "typedef",
    "typeid", "typename",
    "union", "unsigned",
    "using", "virtual",
    "void", "volatile",
    "wchar_t", "while",
    "xor", "xor_eq" };
void tocopy(char* a, const char* b, int len)
{
    for (int i = 0; i <= len; i++)
        a[i] = b[i];
}
ID::ID()
{
    nd;
}
ID::ID(const char* s)
{
    if (!(s[0] >= 97 && s[0] <= 122 || s[0] >= 65 && s[0] <= 90 || s[0] == 95)) {
        nd
    }
    while (s[++len]) {
        if (!(s[len] >= 97 && s[len] <= 122 || s[len] >= 65 && s[len] <= 90 || s[len] == 95 || s[len] >= 48 && s[len] <= 57)) {
            nd
        }
    }
    for (string t : arr) {
        if (s == t) {
            nd
        }
    }
    str = new char[len + 1];
    tocopy(str, s, len);
}
ID::ID(MyStr const& s)
    : ID(s.getCh())
{
}
ID::ID(ID const& s)
{
    len = s.len;
    str = new char[len + 1];
    tocopy(str, s.str, len);
}
