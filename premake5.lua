workspace("iris")
configurations({ "debug", "release" })

project("iris")
kind("ConsoleApp")
language("C++")
cppdialect("C++20")

buildoptions({ "`pkg-config fmt --cflags`" })
linkoptions({ "`pkg-config fmt --libs`" })

files({ "src/**.hpp", "src/**.cpp" })

filter({ "configurations:debug" })
symbols("On")
defines({ "DEBUG" })

filter({ "configurations:release" })
optimize("On")
