vcl_sources = files(
    'instrset_detect.cpp'
)

vcl_lib = library('rhc',
    vcl_sources,
    include_directories : vcl_inc,
    version : meson.project_version(),
    soversion : meson.project_version(),
    install : not meson.is_subproject()
)