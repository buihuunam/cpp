def count_letters(word):
    # Chuyển tất cả chữ cái về dạng chữ thường để việc so sánh dễ dàng hơn
    word = word.lower()
    
    # Khởi tạo dictionary để lưu kết quả
    letter_count = {}
    
    # Duyệt qua từng chữ cái trong từ
    for letter in word:
        if letter in letter_count:
            letter_count[letter] += 1
        else:
            letter_count[letter] = 1
    
    return letter_count

word = input("Nhập một từ: ")
result = count_letters(word)
print(result)
