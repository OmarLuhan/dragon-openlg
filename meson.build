project('dragon-opengl', 'cpp',
  version : '1.0',
  default_options : ['cpp_std=c++11', 'warning_level=3'])

# Buscar dependencias del sistema
gl_dep = dependency('gl')
glu_dep = dependency('glu')
glut_dep = dependency('glut')

# Especificar archivos fuente
sources = [
  'src/main.cpp',
  'src/texture.cpp',
  'src/glm.cpp',
]

# Especificar directorios de include
inc = include_directories('dependencies/include')

# Crear el ejecutable
executable('dragon-opngl',
  sources,
  include_directories : inc,
  dependencies : [gl_dep, glu_dep, glut_dep],
  cpp_args : ['-Wall', '-fexceptions'],
  install : true
)
