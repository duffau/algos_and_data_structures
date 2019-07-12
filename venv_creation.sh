#!/usr/bin/env bash

virtualenv --no-site-packages  -p /usr/bin/python2.7 venv
venv/bin/pip install --upgrade pip
venv/bin/pip install -r requirements.txt --process-dependency-links
