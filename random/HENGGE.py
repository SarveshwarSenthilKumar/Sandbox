def main():
    test_count = int(input())
    answers = []

    def read_cases(cases_left):
        if cases_left == 0:
            return

        expected_count = int(input())
        numbers = input().split()

        if len(numbers) != expected_count:
            answers.append("-1")
        else:
            values = map(int, numbers)
            non_positive = filter(lambda number: number <= 0, values)
            powers = map(lambda number: number ** 4, non_positive)
            answers.append(str(sum(powers)))

        read_cases(cases_left - 1)

    read_cases(test_count)
    print("\n".join(answers))


if __name__ == "__main__":
    main()