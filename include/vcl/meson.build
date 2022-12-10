vcl_headers = files(
    'instrset.h',
    'vectorclass.h',
    'vector_convert.h',
    'vectorf128.h',
    'vectorf256e.h',
    'vectorf256.h',
    'vectorf512e.h',
    'vectorf512.h',
    'vectorfp16e.h',
    'vectorfp16.h',
    'vectori128.h',
    'vectori256e.h',
    'vectori256.h',
    'vectori512e.h',
    'vectori512.h',
    'vectori512se.h',
    'vectori512s.h',
    'vectormath_common.h',
    'vectormath_exp.h',
    'vectormath_hyp.h',
    'vectormath_lib.h',
    'vectormath_trig.h',
)

if not meson.is_subproject()
    # needed when using `meson install` so headers end up in /usr/local/include
    install_headers(vcl_headers, subdir : proj_inc_dir)
endif
