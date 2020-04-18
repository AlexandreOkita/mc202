#!/bin/bash

#instala pacotes
/usr/bin/apm install \
     linter linter-ui-default linter-gcc \
     linter-c-indentation intentions \
     busy-signal auto-detect-indentation

# se já existe arquivo de configuração, faz backup e remove seções
if [ -f ~/.atom/config.cson ] ; then
    mv ~/.atom/config.cson ~/.atom/config.cson.backup
    cat ~/.atom/config.cson.backup | \
        sed -re '/^  editor:/,/^  [^ ]/ { /^  (  |editor:)/ d }' | \
        sed -re '/^  "linter-gcc":/,/^  [^ ]/ { /^  (  |"linter-gcc":)/ d }'  \
        > ~/.atom/config.cson
# se não existe, cria
else
    mkdir -p ~/.atom
    echo '"*":' > ~/.atom/config.cson
fi

# adiciona seções
cat << EOF >> ~/.atom/config.cson
  editor:
    tabLength: 4
  "linter-gcc":
    execPath: "/usr/bin/gcc"
    gccDefaultCFlags: "-ansi -Wall -pedantic-errors -Werror -g -lm"
EOF
