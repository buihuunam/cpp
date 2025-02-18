def initialize_dp_matrix(m, n):
    """Khởi tạo ma trận dp với kích thước (m+1) x (n+1) và thiết lập các giá trị ban đầu."""
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Khởi tạo các giá trị cho dp
    for i in range(m + 1):
        dp[i][0] = i  # Khoảng cách từ S[0...i] đến chuỗi rỗng
    for j in range(n + 1):
        dp[0][j] = j  # Khoảng cách từ chuỗi rỗng đến T[0...j]
    
    return dp


def compute_levenshtein_distance(source, target):
    """Tính toán khoảng cách Levenshtein giữa hai chuỗi source và target."""
    m = len(source)
    n = len(target)
    
    # Khởi tạo ma trận dp
    dp = initialize_dp_matrix(m, n)
    
    # Điền ma trận dp bằng cách tính toán 3 phép biến đổi
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if source[i - 1] == target[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]  # Nếu giống nhau, không cần thay thế
            else:
                dp[i][j] = min(
                    dp[i - 1][j] + 1,   # Xoá
                    dp[i][j - 1] + 1,   # Thêm
                    dp[i - 1][j - 1] + 1  # Thay thế
                )
    
    return dp[m][n]


def levenshtein_distance(source, target):
    """Hàm chính tính toán khoảng cách Levenshtein giữa hai chuỗi."""
    return compute_levenshtein_distance(source, target)


# Ví dụ sử dụng:
source = input("Nhập chuỗi nguồn (source): ")
target = input("Nhập chuỗi đích (target): ")
result = levenshtein_distance(source, target)
print(f"Levenshtein distance between '{source}' and '{target}': {result}")
