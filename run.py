#!/usr/bin/env python
# This script will build and run the project

import os
import platform
import subprocess

# Set project name
project_name = 'Devialify'

# Determine the current platform
is_windows = platform.system() == 'Windows'

# Create a build directory if it doesn't exist
if not os.path.exists('build'):
    os.makedirs('build')
os.chdir('build')

# Configure the project
cmake_args = ['cmake', '..']
if is_windows:
    cmake_args += ['-DCMAKE_GENERATOR_PLATFORM=x64']
subprocess.check_call(cmake_args)

# Build the application
if is_windows:
    subprocess.check_call(['cmake', '--build', '.', '--config', 'Release'])
else:
    subprocess.check_call(['make'])

# Run the application
if is_windows:
    subprocess.check_call([f'.\\bin\\{project_name}.exe'])
else:
    subprocess.check_call([f'./bin/{project_name}'])
