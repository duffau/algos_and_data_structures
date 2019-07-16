#!/usr/bin/env bash

virtualenv --no-site-packages  -p /usr/bin/python3 venv
venv/bin/pip install --upgrade pip
venv/bin/pip install -r requirements.txt