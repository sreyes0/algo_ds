set WS_ROOT $PROJECTS/algo_ds

function build_procedure
    pushd .
    cd $WS_ROOT
    cmake -S . -B build
    cmake --build build
    popd
end

function test_procedure
    pushd .
    cd $WS_ROOT
    ctest --test-dir build
    popd
end

alias build="build_procedure"
alias testit="test_procedure"
alias home="cd $WS_ROOT"

