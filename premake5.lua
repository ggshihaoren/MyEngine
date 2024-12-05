workspace "Lin"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    project "Lin"
        location "Lin"
        kind "SharedLib"
        language "C++"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        pchheader "Lpch.h"
        pchsource "Lin/src/Lpch.cpp"

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "%{prj.name}/src",
            "%{prj.name}/vendor/spdlog/include"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"
            

            defines
            {
                "LIN_PLATFORM_WINDOWS",
                "LIN_BUILD_DLL"
            }


            buildoptions {"/utf-8"}
    

        filter "configurations:Debug"
            defines "LIN_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "LIN_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "LIN_DIST"
            optimize "On"


    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        buildoptions {"/utf-8"}

        includedirs
        {
            "Lin/vendor/spdlog/include",
            "Lin/src"
        }

        links
        {
            "Lin"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines
            {
                "LIN_PLATFORM_WINDOWS"
            }

           postbuildcommands
            {
                -- 将 Lin/Lin.dll 复制到 Sandbox 的输出目录
                ("{COPY} %{wks.location}/bin/" .. outputdir .. "/Lin/Lin.dll %{wks.location}/bin/" .. outputdir .. "/Sandbox")
            }

        filter "configurations:Debug"
            defines "LIN_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "LIN_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "LIN_DIST"
            optimize "On"