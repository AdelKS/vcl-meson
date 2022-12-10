project('vector-class-library', 'cpp',
    version : '2.02.00',
    default_options : [
        'cpp_std=c++17',
        'buildtype=release',
        'optimization=3',
        'default_library=shared',
        'c_args=-march=native -pipe',
        'cpp_args=-march=native -pipe',
        'warning_level=3',
        'werror=true'
    ]
)

fs = import('fs')

proj_inc_dir = 'vcl'

vcl_inc = include_directories('include')

subdir('include/vcl')
subdir('src')

vcl_dep = declare_dependency(
    include_directories : vcl_inc,
    link_with : vcl_lib,
)

