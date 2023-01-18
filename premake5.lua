-- premake5.lua
workspace "golf"
    configurations { "Debug", "Release" }
    
project "golf"  
    kind "ConsoleApp"
    language "C++"   
    cppdialect "C++latest"
    architecture "x86_64"

    targetdir "bin/%{cfg.buildcfg}" 

    defines { "GAME_PLATFORM_WINDOWS", "SFML_STATIC" }

    files { "src/**.h", "src/**.cpp" } 

    includedirs
    {
       "thirdparty/sfml/include",
       "src"
    }

    libdirs
    { 
        "thirdparty/sfml/lib" 
    }

    links 
    { 
        "opengl32.lib", 
        "freetype.lib",
        "winmm.lib", 
        "gdi32.lib", 
        "openal32.lib", 
        "flac.lib", 
        "vorbisenc.lib", 
        "vorbisfile.lib", 
        "vorbis.lib", 
        "ogg.lib", 
        "ws2_32.lib",
    }

    filter "configurations:Debug"
        defines { "DEBUG" }  
        symbols "On"
        links 
        { 
            "sfml-audio-s-d.lib", 
            "sfml-graphics-s-d.lib", 
            "sfml-network-s-d.lib", 
            "sfml-system-s-d.lib", 
            "sfml-window-s-d.lib" 
        }

    filter "configurations:Release"  
        defines { "NDEBUG" }    
        optimize "On"   
        links 
        { 
            "sfml-audio-s.lib", 
            "sfml-graphics-s.lib", 
            "sfml-network-s.lib", 
            "sfml-system-s.lib", 
            "sfml-window-s.lib" 
        }