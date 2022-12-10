vcl_test_sources = files(
    'sin_cos_lookup.cpp',
)

foreach test_src: vcl_test_sources
    test_exe = executable(
        fs.stem(test_src), # name executable after source file without .cpp extension
        test_src, # source file path
        dependencies : vcl_dep # dependencies, here the vcl headers
    )

    test(fs.stem(test_src), test_exe) # register as a test
endforeach
