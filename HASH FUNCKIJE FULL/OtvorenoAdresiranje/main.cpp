#include "OpenScatterTable.h"
const char* keywords[] = {
  "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor",
  "bool", "break", "case", "catch", "char", "char16_t", "char32_t", "class",
  "compl", "const", "constexpr", "const_cast", "continue", "decltype",
  "default", "delete", "do", "double", "dynamic_cast", "else", "enum",
  "explicit", "export", "extern", "false", "float", "for", "friend", "goto",
  "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept",
  "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private",
  "protected", "public", "register", "reinterpret_cast", "return", "short",
  "signed", "sizeof", "static", "static_assert", "static_cast", "struct",
  "switch", "template", "this", "thread_local", "throw", "true", "try",
  "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual",
  "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
};

int main() {
	OpenScatterTable ost(128);
	for (int i = 0; i < 84; i++)
		ost.insert(OpenScatterObject(keywords[i], "sth"));
	ost.print();
	//ost.find("static").print();
	//cout << endl;
	//ost.find("nesto").print();
	ost.withdraw("static");
	ost.print();
	ost.insert(OpenScatterObject("statin", "stgh"));
	ost.print();
	return 0;
}