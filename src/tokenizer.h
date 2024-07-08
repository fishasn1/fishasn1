#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <stdbool.h>

#define ABSENT "ABSENT"
#define ABSTRACT_SYNTAX "ABSTRACT-SYNTAX"
#define ALL "ALL"
#define APPLICATION "APPLICATION"
#define AUTOMATIC "AUTOMATIC"
#define BEGIN "BEGIN"
#define BIT "BIT"
#define BMPString "BMPString"
#define BOOLEAN "BOOLEAN"
#define BY "BY"
#define CHARACTER "CHARACTER"
#define CHOICE "CHOICE"
#define CLASS "CLASS"
#define COMPONENT "COMPONENT"
#define COMPONENTS "COMPONENTS"
#define CONSTRAINED "CONSTRAINED"
#define CONTAINING "CONTAINING"
#define DATE "DATE"
#define DATE_TIME "DATE-TIME"
#define DEFAULT "DEFAULT"
#define DEFINITIONS "DEFINITIONS"
#define DURATION "DURATION"
#define EMBEDDED "EMBEDDED"
#define ENCODED "ENCODED"
#define ENCODING_CONTROL "ENCODING-CONTROL"
#define END "END"
#define ENUMERATED "ENUMERATED"
#define EXCEPT "EXCEPT"
#define EXPLICIT "EXPLICIT"
#define EXPORTS "EXPORTS"
#define EXTENSIBILITY "EXTENSIBILITY"
#define EXTERNAL "EXTERNAL"
#define FALSE "FALSE"
#define FROM "FROM"
#define GeneralizedTime "GeneralizedTime"
#define GeneralString "GeneralString"
#define GraphicString "GraphicString"
#define IA5String "IA5String"
#define IDENTIFIER "IDENTIFIER"
#define IMPLICIT "IMPLICIT"
#define IMPLIED "IMPLIED"
#define IMPORTS "IMPORTS"
#define INCLUDES "INCLUDES"
#define INSTANCE "INSTANCE"
#define INSTRUCTIONS "INSTRUCTIONS"
#define INTEGER "INTEGER"
#define INTERSECTION "INTERSECTION"
#define ISO646String "ISO646String"
#define MAX "MAX"
#define MIN "MIN"
#define MINUS_INFINITY "MINUS-INFINITY"
#define NOT_A_NUMBER "NOT-A-NUMBER"
#define _NULL "NULL"
#define NumericString "NumericString"
#define OBJECT "OBJECT"
#define ObjectDescriptor "ObjectDescriptor"
#define OCTET "OCTET"
#define OF "OF"
#define OID_IRI "OID-IRI"
#define OPTIONAL "OPTIONAL"
#define PATTERN "PATTERN"
#define PDV "PDV"
#define PLUS_INFINITY "PLUS-INFINITY"
#define PRESENT "PRESENT"
#define PrintableString "PrintableString"
#define PRIVATE "PRIVATE"
#define REAL "REAL"
#define RELATIVE_OID "RELATIVE-OID"
#define RELATIVE_OID_IRI "RELATIVE-OID-IRI"
#define SEQUENCE "SEQUENCE"
#define SET "SET"
#define SETTINGS "SETTINGS"
#define SIZE "SIZE"
#define STRING "STRING"
#define SYNTAX "SYNTAX"
#define T61String "T61String"
#define TAGS "TAGS"
#define TeletexString "TeletexString"
#define TIME "TIME"
#define TIME_OF_DAY "TIME-OF-DAY"
#define TRUE "TRUE"
#define TYPE_IDENTIFIER "TYPE-IDENTIFIER"
#define UNION "UNION"
#define UNIQUE "UNIQUE"
#define UNIVERSAL "UNIVERSAL"
#define UniversalString "UniversalString"
#define UTCTime "UTCTime"
#define UTF8String "UTF8String"

typedef enum {
        TOKEN_ABSENT,
        TOKEN_ABSTRACT_SYNTAX,
        TOKEN_ALL,
        TOKEN_APPLICATION,
        TOKEN_AUTOMATIC,
        TOKEN_BEGIN,
        TOKEN_BIT,
        TOKEN_BMPString,
        TOKEN_BOOLEAN,
        TOKEN_BY,
        TOKEN_CHARACTER,
        TOKEN_CHOICE,
        TOKEN_CLASS,
        TOKEN_COMPONENT,
        TOKEN_COMPONENTS,
        TOKEN_CONSTRAINED,
        TOKEN_CONTAINING,
        TOKEN_DATE,
        TOKEN_DATE_TIME,
        TOKEN_DEFAULT,
        TOKEN_DEFINITIONS,
        TOKEN_DURATION,
        TOKEN_EMBEDDED,
        TOKEN_ENCODED,
        TOKEN_ENCODING_CONTROL,
        TOKEN_END,
        TOKEN_ENUMERATED,
        TOKEN_EXCEPT,
        TOKEN_EXPLICIT,
        TOKEN_EXPORTS,
        TOKEN_EXTENSIBILITY,
        TOKEN_EXTERNAL,
        TOKEN_FALSE,
        TOKEN_FROM,
        TOKEN_GeneralizedTime,
        TOKEN_GeneralString,
        TOKEN_GraphicString,
        TOKEN_IA5String,
        TOKEN_IDENTIFIER,
        TOKEN_IMPLICIT,
        TOKEN_IMPLIED,
        TOKEN_IMPORTS,
        TOKEN_INCLUDES,
        TOKEN_INSTANCE,
        TOKEN_INSTRUCTIONS,
        TOKEN_INTEGER,
        TOKEN_INTERSECTION,
        TOKEN_ISO646String,
        TOKEN_MAX,
        TOKEN_MIN,
        TOKEN_MINUS_INFINITY,
        TOKEN_NOT_A_NUMBER,
        TOKEN_NULL,
        TOKEN_NumericString,
        TOKEN_OBJECT,
        TOKEN_ObjectDescriptor,
        TOKEN_OCTET,
        TOKEN_OF,
        TOKEN_OID_IRI,
        TOKEN_OPTIONAL,
        TOKEN_PATTERN,
        TOKEN_PDV,
        TOKEN_PLUS_INFINITY,
        TOKEN_PRESENT,
        TOKEN_PrintableString,
        TOKEN_PRIVATE,
        TOKEN_REAL,
        TOKEN_RELATIVE_OID,
        TOKEN_RELATIVE_OID_IRI,
        TOKEN_SEQUENCE,
        TOKEN_SET,
        TOKEN_SETTINGS,
        TOKEN_SIZE,
        TOKEN_STRING,
        TOKEN_SYNTAX,
        TOKEN_T61String,
        TOKEN_TAGS,
        TOKEN_TeletexString,
        TOKEN_TIME,
        TOKEN_TIME_OF_DAY,
        TOKEN_TRUE,
        TOKEN_TYPE_IDENTIFIER,
        TOKEN_UNION,
        TOKEN_UNIQUE,
        TOKEN_UNIVERSAL,
        TOKEN_UniversalString,
        TOKEN_UTCTime,
        TOKEN_UTF8String,
        TOKEN_UNKNOWN
} TOKEN_TYPE_ENUM;

typedef struct {
        TOKEN_TYPE_ENUM type;
        unsigned char *value;
} token_t;

typedef struct {
    char *stream;
    unsigned int pos;
} tokenizer_t;

bool is_eof(char ch);
bool is_white_space(char ch);
char next_char(tokenizer_t *tokenizer);
char peek_char(tokenizer_t *tokenizer);

token_t*
next_token(tokenizer_t *tokenizer);
#endif /* TOKENIZER_H_ */
