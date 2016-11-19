#!/bin/bash
cd $(pwd)
git add -A
git commit  -m "$1 at $(date +"%H:%M") of $(date +"%d-%m-%Y")"
git push -u origin $(git rev-parse --abbrev-ref HEAD)
