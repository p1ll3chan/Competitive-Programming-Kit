#!/bin/bash

# add all files
git add .

# commit with date
git commit -m "Practice update: $(date)"

# push to github
git push origin main
