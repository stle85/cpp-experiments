#!/usr/bin/env bash

# Regenerate compilation database
gen_compilation_database.py

# Kill clangd to reload the compilation database
pkill clangd || :
