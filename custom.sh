#!/bin/bash
# Custom script to extract and overwrite files from extension_ledspicer.tar.gz

# Define the source file path
source_file="/userdata/system/extension_ledspicer.tar.gz"

# Check if the source file exists
if [ -f "$source_file" ]; then
    # Check if the file is in gzip format
    if file -b --mime-type "$source_file" | grep -q gzip; then
        # Extract the contents of the tar.gz file to the root directory
        if sudo tar -xzvf "$source_file" -C /; then
            echo "Files extracted successfully."

            # Set executable permissions for files in /usr/bin
            sudo chmod +x /usr/bin/emitter /usr/bin/inputseeker /usr/bin/ledspicerd /usr/bin/processLookup /usr/bin/rotator
            echo "Executable permissions set for files in /usr/bin."
        else
            echo "Error occurred during extraction. Exiting."
        fi
    else
        echo "Source file $source_file is not in gzip format."
    fi
else
    echo "Source file $source_file not found."
fi
