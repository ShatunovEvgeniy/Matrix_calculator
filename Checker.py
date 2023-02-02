f_res = open("C++_result.txt", "r")
f_ans = open("answers.txt", "r")
f_review = open("review.txt", "w")


def difference(ans, res):
    string = ''
    for j in range(len(ans)):
        string += ' '.join([str(i) for i in ans[j]]) + '\t' + ' '.join([str(i) for i in res[j]]) + '\n'

    string += '\n\n\n\n'
    return string


numbers_ans = []
numbers_res = []
while True:
    try:
        s = f_ans.readline()
        if s == '':
            break
        elif s == '\n':
            if numbers_ans != numbers_res:
                f_review.write(difference(numbers_ans, numbers_res))
            f_res.readline()
            numbers_ans = []
            numbers_res = []
        else:
            numbers_ans.append(s.split())
            numbers_res.append(f_res.readline().split())
            # if any([not number.isnumeric() for number in numbers_res[-1]]) or any([not number.isnumeric() for number in numbers_ans[-1]]):
            #     raise ValueError("Unknown symbols")

    except ValueError as e:
        f_review.write(repr(e) + '\n\n')
        f_review.write(difference(numbers_ans, numbers_res))

f_res.close()
f_ans.close()
f_review.close()