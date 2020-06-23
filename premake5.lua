workspace "Crispy"
    architecture "x86_64"
    configurations{
        "Debug",
        "Release",
        "Dist"
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Crispy"
    location "Crispy"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")
    
    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs{
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
            "CY_PLATFORM_WINDOWS",
            "CY_BUILD_DLL"
        }

        postbuildcommands{
            ("{COPY}} %{cfg.buildtarget.relpath} ../bin/" ..outputDir.. "/Sandbox/")
        }

    filter "configurations:Debug"
        defines "CY_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CY_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "CY_DIST"
        optimize "On"

    -- filter{"system:windows","configuration:Release"}
    --     buildoptions "/MT"

project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputDir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

        files{
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }
    
        includedirs{
            "Crispy/vendor/spdlog/include",
            "Crispy/src"
        }

        links{
            "Crispy"
        }
    
        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"
    
            defines{
                "CY_PLATFORM_WINDOWS",
            }

        filter "configurations:Debug"
            defines "CY_DEBUG"
            symbols "On"
    
        filter "configurations:Release"
            defines "CY_RELEASE"
            optimize "On"
    
        filter "configurations:Dist"
            defines "CY_DIST"
            optimize "On"
    