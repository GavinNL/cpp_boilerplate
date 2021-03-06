#!/bin/bash

if [[ "$(uname -s)" == 'Darwin' ]]; then
    brew update || brew update
    brew outdated pyenv || brew upgrade pyenv
    brew install pyenv-virtualenv
    brew install cmake || true

    if which pyenv > /dev/null; then
        eval "$(pyenv init -)"
    fi

    pyenv install 2.7.10
    pyenv virtualenv 2.7.10 conan
    pyenv rehash
    pyenv activate conan
    pip install --upgrade pip
    pip install conan --upgrade
else
    pip install --user --upgrade pip
    pip install --user conan --upgrade
fi

conan user
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan

