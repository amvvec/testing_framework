#!/ bin / bash

echo "[ PRE-COMMIT ] Running clang-format..."

    FILES = $(git diff-- cached-- name - only-- diff - filter =
                  ACM | grep - E '\.(cpp|h)$')

        if[-z "$FILES"]; then
    echo "[ PRE-COMMIT ] No .h or .cpp files to format."
    exit 0
fi

for file in $FILES;
do
    if clang
        - format - i "$file";
then echo "[ PRE-COMMIT ] Error: clang-format failed on $file" exit 1 fi git add
        "$file" done

            echo "[ PRE-COMMIT ] Done: formated and staged files."

        if git -
        diff-- cached-- name - only |
    grep - E '\.(cpp|h)$' |
    xargs grep - nE 'TODO|FIX|DEBUG\s*<<' --exclude -
        dir =.git-- exclude - dir = build-- exclude - dir =.vscode;
then echo
    "[ PRE-COMMIT ] Error: Found TODO, FIX, or DEBUG in staged files!" echo
    "[ PRE-COMMIT ] Commit blocked." exit 1 fi

        echo "[ PRE-COMMIT ] No TODO|FIX|DEBUG found." exit 0
