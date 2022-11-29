import qbs

CppApplication {
    consoleApplication: true
    install: true
    files: [
        "column.cpp",
        "column.h",
        "main.cpp",
        "matrix.cpp",
        "matrix.h",
        "row.cpp",
        "row.h",
    ]
}
