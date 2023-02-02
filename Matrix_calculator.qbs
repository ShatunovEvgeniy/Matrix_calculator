import qbs

Project {

    CppApplication {
        consoleApplication: true
        install: true
        property path lib_dir: "Lib"
        files: [
            "Files work/others_functions.cpp",
            "Files work/others_functions.h",
            "Graphic/vector_window.cpp",
            "Graphic/vector_window.h",
            lib_dir +"/Graph_lib/Graph.cpp",
            lib_dir +"/Graph_lib/GUI.cpp",
            lib_dir +"/Graph_lib/Window.cpp",
            "Graphic/Matrix_out.cpp",
            "Graphic/Matrix_out.h",
            "Files work/streams.cpp",
            "Files work/streams.h",
            "Graphic/Calc_window.cpp",
            "Graphic/Calc_window.h",
            "Graphic/Matrix_in.cpp",
            "Graphic/Matrix_in.h",
            "Logic/column.cpp",
            "Logic/column.h",
            "main.cpp",
            "Logic/matrix.cpp",
            "Logic/matrix.h",
            "Logic/row.cpp",
            "Logic/row.h",
            "Logic/sqr_matrix.cpp",
            "Logic/sqr_matrix.h",
            "Logic/vector.cpp",
            "Logic/vector.h",
        ]


        cpp.includePaths: lib_dir
        Properties {
            condition: qbs.targetOS.contains("windows")
            cpp.defines: "WIN32"
            cpp.systemIncludePaths: lib_dir + "/fltk-1.3.8_win64/include"
            cpp.libraryPaths: lib_dir + "/fltk-1.3.8_win64/lib"
            cpp.driverLinkerFlags: "-mwindows"
            cpp.staticLibraries: [
                "fltk_images",
                "fltk",
                "fltk_png",
                "fltk_z",
                "fltk_jpeg",
                "ole32",
                "uuid",
                "comctl32",
            ]
        }

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }
    }
}
