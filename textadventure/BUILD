cc_binary(
    name = "main",
    srcs = [
        "main.cc",
    ],
    deps = [
        ":lib",
    ],
)

cc_library(
    name = "lib",
    srcs = glob(
        ["*.cc"],
        exclude = ["main.cc"],
    ),
    hdrs = glob(["*.h"]),
    deps = [],
)
