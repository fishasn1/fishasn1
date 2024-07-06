project('fishasn1', 'c')

subdir('src')
subdir('test')

libs = [
  tokenizer_lib
]

executable('fishasn1', main_source, link_with: libs)

# Tests 
test_tokenizer_exe = executable('test_tokenizer', test_tokenizer_source, 
    include_directories: include_directories('./src'),
    link_with: libs)

test('test_tokenizer', test_tokenizer_exe)
