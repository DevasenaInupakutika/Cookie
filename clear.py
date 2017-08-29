#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import subprocess
from dateutil import parser
from datetime import datetime, timedelta

threshold = datetime.today() - timedelta(days=300)


def clear(path, start):
    for file_name in os.listdir(path):
        file_path = os.path.join(path, file_name)
        if file_name[0] == '.':
            continue
        if os.path.isdir(file_path):
            clear(file_path, True)
        else:
            if start:
                cmd = 'git log "%s" | head -n 3 | tail -n 1' % file_path
                output = subprocess.check_output(cmd, shell=True).strip()[8:]
                date = parser.parse(output).replace(tzinfo=None)
                if date < threshold:
                    print(file_path)
                    os.remove(file_path)

clear('.', False)
