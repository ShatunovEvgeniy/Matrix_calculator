import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
        consoleApplication: true

        cpp.cxxLanguageVersion: "c++17"

        property path lib_dir: "C:/Users/timti/OneDrive/proektQT/lib"

        files: [
            "Calc_window.cpp",
            "Calc_window.h",
            "Matrix_in.cpp",
            "Matrix_in.h",
            "Matrix_out.cpp",
            "Matrix_out.h",
            "column.cpp",
            "column.h",
            "matrix.cpp",
            "matrix.h",
            "other_functions.cpp",
            "other_functions.h",
            "row.cpp",
            "row.h",
            "sqr_matrix.cpp",
            "sqr_matrix.h",
            lib_dir +"/Graph.cpp",
            lib_dir +"/GUI.cpp",
            lib_dir +"/Window.cpp",
            lib_dir +"/Graph_dop.cpp",
            "main.cpp",
        ]

        cpp.includePaths: lib_dir
        Properties {
            condition: qbs.targetOS.contains("windows")
            cpp.defines: "WIN32"
            cpp.systemIncludePaths: lib_dir+"/fltk/include"
            cpp.libraryPaths: lib_dir+"/fltk/lib"
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
        Properties {
            condition: qbs.targetOS.contains("linux")
            cpp.systemIncludePaths: "/home/vova/opt/fltk-1.3.7/include"
            cpp.libraryPaths: "/home/vova/opt/fltk-1.3.7/lib"
            cpp.staticLibraries: [
                "fltk_images",
                "png",
                "z",
                "jpeg",
                "fltk",
                "Xrender",
                "Xcursor",
                "Xfixes",
                "Xext",
                "Xft",
                "fontconfig",
                "Xinerama",
                "dl",
                "m",
                "X11",
            ]
        }

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }
    }
}
