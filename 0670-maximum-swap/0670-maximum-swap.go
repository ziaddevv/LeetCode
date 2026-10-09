func reverse(s string) string {
	chars := []rune(s)

	for i, j := 0, len(chars)-1; i < j; i, j = i+1, j-1 {
		chars[i], chars[j] = chars[j], chars[i]
	}

	return string(chars)
}
func maximumSwap(num int) int {

	str := ""
	tmp := num
	for tmp > 0 {

		str += string('0' + (tmp % 10))

		tmp /= 10
	}

	characters := []rune(str)
	sort.Slice(characters, func(i, j int) bool {
		return characters[i] > characters[j]
	})

	str = reverse(str)

	// fmt.Println(string(characters))
	// slices.Sort(str)

	start := -1
	end := -1

	for i, v := range characters {
		if string(v) != string(str[i]) {
			start = i
			break
		}
	}

	if start == -1 {
		return num
	}

	for i, v := range str {
		if string(v) == string(characters[start]) {
			end = i
		}
	}


	chars := []rune(str)

	chars[start], chars[end] = chars[end], chars[start]

	str = string(chars)
	num1 ,_ := strconv.Atoi(str)
	return num1
}

// 2736
// 7632

// 9725
// 9 7 5 2