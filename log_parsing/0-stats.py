#!/usr/bin/python3
"""Log parsing"""
import datetime
import sys

status = [200, 301, 400, 401, 403, 404, 405, 500]
status_count = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}


def parse(line):
    """Parse a line"""
    try:
        parts = line.strip().split()
        status_code = int(parts[-2])
        file_size = int(parts[-1])
        if status_code not in status:
            return None
        return {"status_code": status_code, "file_size": file_size}
    except (ValueError, IndexError):
        return None


def parse10(data_list):
    """parse 10 lines of generated logs"""
    file_size = 0
    for data in data_list:
        file_size += data["file_size"]
        status_count[data["status_code"]] += 1
    return file_size, status_count



def print_stats(file_size, status_count):
    """print stats"""
    print(f"File size: {file_size}")
    for code in sorted(status):
        count = status_count.get(code, 0)
        if count > 0:
            print(f"{code}: {count}")


if __name__ == "__main__":
    data_list = []
    h = 0
    try:
        for input_line in sys.stdin:
            if input_line.strip() == "":
                print("file size: 0")
            else:
                data = parse(input_line)
                if data:
                    data_list.append(data)
                    if len(data_list) == 10:
                        file_size, status_count = parse10(data_list)
                        h = file_size
                        print_stats(file_size, status_count)
                        data_list = []
        # emptying the buffer
        if data_list:
            x, y = parse10(data_list)
            x += h
            print_stats(x, y)
    except KeyboardInterrupt:
        print("KeyboardInterrupt")
        exit(0)
