
def test(name, expected, result):
    if(type(expected) == type("")):
        expected = expected.replace("\n", "")
        result = result.replace("\n", "")
    if expected == result:
        print("✅ Test \"" + name + f"\" passed! (result: {result})")
    else:
        print("❌ Test \"" + name + f"\" failed! (expected {expected}, got {result})")

def n_of_lines(path):
    f = open(path, "r")
    return len(f.readlines())

def n_of_characters_per_line(path):
    f = open(path, "r")
    res = ""
    line = f.readline()
    while line:
        res += str(len(line)-(1 if line.endswith("\n") else 0)) + "\n"
        line = f.readline()
    return res

def n_of_characters(path):
    f = open(path, "r")
    res = 0
    line = f.readline()
    while line:
        res += len(line)-1
        line = f.readline()
    return res

def file_size(path):
    f = open(path, "r")
    sum = 0
    line = f.readline()
    while line:
        sum += len(line)
        line = f.readline()
    return sum

if __name__ == "__main__":
    print()
    path1 = "test_file.txt"
    print("Testing " + path1)
    test("Number of lines", 3, n_of_lines(path1))
    test("Characters per line", "5\n5\n5\n", n_of_characters_per_line(path1))
    test("Total characters", 15, n_of_characters(path1))
    test("File size", 18, file_size(path1))

    print()
    path2 = "test_file2.txt"
    print("Testing " + path2)
    test("Number of lines", 5, n_of_lines(path2))
    test("Characters per line", "4\n3\n3\n3\n3\n", n_of_characters_per_line(path2))
    test("Total characters", 15, n_of_characters(path2))
    test("File size", 20, file_size(path2))
    print()

