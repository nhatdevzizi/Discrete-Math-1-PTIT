# Discrete Math 1 – PTIT — Giải thích các bài giải

Repo này chứa các bài giải bằng C++ cho môn Toán rời rạc 1 (Discrete Math 1) trên CODEPTIT. Tất cả các file đều dùng chung một phần khung code (`#define ll long long`, nhập/xuất nhanh qua `boost`, cùng vài biến toàn cục dư thừa như `arr`, `k`, `a`, `b`...), nên phần mô tả dưới đây sẽ tập trung vào nội dung thuật toán thực sự của từng file.

Các file được nhóm theo **chủ đề** thay vì theo tên file, vì mã `TRR1_xxxx` / `LT004` chỉ là mã số bài trên hệ thống chấm.

## Mục lục
- [Tập hợp](#tập-hợp)
- [Số học & Đếm](#số-học--đếm)
- [Sinh tổ hợp (hoán vị, chỉnh hợp, tập con)](#sinh-tổ-hợp-hoán-vị-chỉnh-hợp-tập-con)
- [Quay lui / Nhánh cận cho bài toán tối ưu](#quay-lui--nhánh-cận-cho-bài-toán-tối-ưu)
- [Bài toán công thức / lặt vặt khác](#bài-toán-công-thức--lặt-vặt-khác)

---

## Tập hợp

| File | Đề bài | Cách giải |
|---|---|---|
| `TRR1_1017.cpp` | **Hợp của hai tập hợp.** Đọc hai mảng chỉ số (1 = phần tử có mặt) trên `1..n`, in ra tập hợp là hợp của chúng. | Đưa các chỉ số của cả hai mảng vào chung một `std::set<int>` (tự động sắp xếp và loại trùng), sau đó in kích thước và nội dung. |
| `TRR1_1018.cpp` | **Giao của hai tập hợp.** Định dạng đầu vào giống bài trên. | Tạo hai `std::set<int>`, chỉ giữ lại các chỉ số xuất hiện ở cả hai tập. |

## Số học & Đếm

| File | Đề bài | Cách giải |
|---|---|---|
| `TRR1_1009.cpp` | **Xác định dấu của tích `a·b`.** Cho hai số thực `a, b`, kiểm tra `a·b ≥ 0`. | Xét trực tiếp các trường hợp: cùng dấu (cùng dương hoặc cùng âm) → in `1`; `a = 0` và `b = 0` → in `1`; còn lại → in `0`. Không thực hiện phép nhân trực tiếp để tránh tràn số/sai số. |
| `TRR1_2002.cpp` | **Đếm bằng nguyên lý bù trừ.** Đếm số nguyên trong `[a, b]` chia hết cho `k` **hoặc** `m`. | Dùng công thức chia lấy phần nguyên `count(bội của d trong [a,b]) = b/d − (a−1)/d`, tính riêng cho `k` và `m`, rồi trừ đi phần đếm trùng (bội của `lcm(k, m)`, tính qua `gcd`). |
| `TRR1_2005.cpp` | **Tổng các số chính phương liên tiếp.** Tìm xem có thể cộng tối đa bao nhiêu số `1², 2², 3², ...` mà tổng không vượt quá `n`. | Cộng dồn `side*side` vào biến `sum` chừng nào còn `≤ n`, đồng thời đếm số hạng đã cộng. |
| `TRR1_2009.cpp` | **Đếm số phân số tối giản phân biệt trong \((0,1]\)** `Σ φ(i)` với `i = 1..n`. | Mỗi phân số tối giản `a/b` (`a ≤ b`, `gcd(a,b)=1`) là duy nhất; với mỗi mẫu số `b`, có đúng `φ(b)` tử số hợp lệ, nên tổng `Σ φ(b)` đếm toàn bộ các phân số phân biệt trong `(0,1]`; cộng thêm `1` nếu cần tính cả phân số `0`. |
| `TRR1_2011.cpp` | **Đếm số xâu nhị phân độ dài `n` không có dãy con `k` bit liên tiếp giống nhau** (không có `k` bit `1` liên tiếp). | Quy hoạch động: `dp[i]` = số xâu hợp lệ độ dài `i`. Với `i < k`, tất cả `2^i` xâu đều hợp lệ; sau đó `dp[i] = dp[i-1] + dp[i-2] + ... + dp[i-k]` (dạng truy hồi kiểu "k-bonacci"). |
| `TRR1_2014.cpp` | **Bài toán bù của bài trên**: đếm số xâu nhị phân độ dài `n` có **ít nhất** một dãy `k` bit liên tiếp giống nhau. | Tính cùng mảng `dp[]` (số xâu *không* có dãy đó), rồi trả về `2^n − dp[n]`. |
| `TRR1_2040.cpp` | **Tổ hợp chập `s` của `n`** `C(n, s)` — số tập con `s` phần tử của tập `n` phần tử. | Hàm `C(n, k)` tự viết theo công thức nhân `C(n,k) = Π (n-i+1)/i`, tính lặp để giảm nguy cơ tràn số (dùng đối xứng `min(k, n-k)`). |
| `TRR1_5021.cpp` | **Bài toán đếm dựa trên số dư khi chia 4.** Chia `1..n` thành ba "lớp" (bội của 4, bội của 2 nhưng không phải 4, và phần còn lại) với số lượng `c4, c2, c1`, sau đó tính `res = c1² + 2·c1·c2` (số cặp thỏa điều kiện chia hết/nguyên tố cùng nhau nào đó theo đề gốc) rồi so sánh với ngưỡng `k`. | Công thức số học suy ra trực tiếp từ việc đếm các lớp; nếu `res < k` thì đáp án là `0`, ngược lại là `res + k`. |
| `TRR1_5022.cpp` | **Đếm tập con loại trừ một họ tập con có kích thước cố định.** Tính `2^n − C(n, k) + 1`, tức tất cả tập con của tập `n` phần tử trừ đi các tập con có `k` phần tử, rồi điều chỉnh `+1`. | Hàm `nCr` tự viết (cùng kỹ thuật công thức nhân như `TRR1_2040.cpp`) kết hợp với dịch bit để tính `2^n`. |

## Sinh tổ hợp (hoán vị, chỉnh hợp, tập con)

Các bài này yêu cầu tìm phần tử **trước/sau** theo một thứ tự từ điển nào đó, hoặc **liệt kê** toàn bộ các đối tượng thỏa điều kiện.

| File | Đề bài | Cách giải |
|---|---|---|
| `TRR1_3006.cpp` | **Hoán vị liền trước** của một mảng số phân biệt. | Duyệt từ phải sang trái tìm vị trí giảm đầu tiên `arr[i] > arr[i+1]`, hoán đổi chúng, rồi sắp xếp phần đuôi `arr[i..n]` theo thứ tự giảm dần (thuật toán "hoán vị liền trước" kinh điển, viết tay thay vì dùng `std::prev_permutation`). In `0` nếu mảng đã là hoán vị nhỏ nhất. |
| `TRR1_3008.cpp` | **Chỉnh hợp chập `k` liền trước** của `{1..n}` theo thứ tự từ điển (giá trị lưu trong `arr[1..k]`). | Duyệt từ phải sang trái tìm vị trí đầu tiên mà `arr[i] ≠ arr[i-1] + 1` (tức chưa "sát" với phần tử trước nó), giảm giá trị đó đi 1. In `0` nếu không còn chỉnh hợp nào trước đó. |
| `TRR1_3011.cpp` | **Hoán vị liền sau, lặp lại `t` lần** trên một mảng. | Cài đặt tay thuật toán "hoán vị liền sau" chuẩn: tìm vị trí tăng gần cuối nhất, tìm phần tử nhỏ nhất bên phải còn lớn hơn nó, hoán đổi, rồi đảo ngược phần đuôi. Lặp lại `t` lần, in `0` khi mảng đã là hoán vị lớn nhất. |
| `TRR1_3015.cpp` | **Xâu nhị phân liền sau theo thứ tự "dãy đuôi", lặp `t` lần.** | Lặp lại việc tìm bit `0` cuối cùng, đặt nó thành `1`, và xóa (đặt về `0`) tất cả các bit sau nó. In `0` khi không còn bit `0` nào. |
| `TRR1_3016.cpp` | **Biến thể ngược lại của `TRR1_3015.cpp`.** | Lặp lại việc tìm bit `1` cuối cùng, đặt nó về `0`, và đặt tất cả các bit sau nó thành `1`. In `0` khi không còn bit `1` nào. |
| `TRR1_3024.cpp` | **Mở rộng một hoán vị bộ phận** (một số vị trí `u → v` đã cố định) thành hoán vị đầy đủ của `1..n`, nếu có thể. | File chứa bản code "AC nhầm" (thuật toán sai nhưng vẫn qua được test) và một **bản code đúng được comment lại phía dưới**. Bản đúng kiểm tra xung đột giữa các vị trí cố định trước (`posFixed[]`/`valueUsed[]`), sau đó quay lui trên các vị trí còn trống, điền các giá trị chưa dùng. In `0` nếu không tồn tại cách hoàn thiện hợp lệ. |
| `TRR1_3025.cpp` | **Liệt kê tất cả chỉnh hợp chập `k` của `{1..n}` có phần tử đầu tiên cố định bằng `t`.** | Quay lui: cố định `arr[1] = t`, chọn đệ quy các giá trị tăng dần nghiêm ngặt cho `k-1` vị trí còn lại, in ra mọi tổ hợp hoàn chỉnh. In `0` nếu không có tổ hợp nào. |
| `TRR1_3026.cpp` | **Liệt kê tất cả chỉnh hợp chập `k` của `{1..n}` có phần tử *cuối cùng* cố định bằng `t`.** | Đối xứng với `TRR1_3025.cpp`: cố định `arr[k] = t` và quay lui từ vị trí 1 trở đi, có kiểm tra khả thi từ đầu (`t < k`, `k > n`, `t > n`). |
| `TRR1_3027.cpp` | **Liệt kê tất cả xâu nhị phân độ dài `n` với một số vị trí được cố định giá trị trước.** | Quay lui trên từng vị trí: nếu vị trí đã cố định trước (`visited[pos]`), giữ nguyên giá trị và đệ quy tiếp; nếu chưa, thử cả hai nhánh `0` và `1`. In mỗi xâu hoàn chỉnh, hoặc `0` nếu không sinh được xâu nào (trường hợp này hiếm khi xảy ra nếu các vị trí cố định hợp lệ). |

## Quay lui / Nhánh cận cho bài toán tối ưu

Các bài toán tối ưu tổ hợp (cái túi, đường đi/chu trình Hamilton, bài toán phân công) được giải bằng quay lui vét cạn, một số có thêm cận để cắt tỉa không gian tìm kiếm.

| File | Đề bài | Cách giải |
|---|---|---|
| `TRR1_4001.cpp` | **Bài toán cái túi 0/1** — tối đa hóa giá trị với sức chứa `b`. | Quay lui thuần túy trên "lấy / không lấy" cho từng món trong `n` món, theo dõi cặp `(tổng giá trị, tổng trọng lượng)` tốt nhất tìm được; không có cận cắt tỉa. |
| `CODE/CT.cpp` | **Bài toán cái túi 0/1 có Nhánh cận (Branch-and-Bound).** | Sắp xếp các món theo tỉ lệ giá trị/trọng lượng; hàm `upperbound()` ước lượng giá trị tốt nhất có thể đạt được từ trạng thái hiện tại bằng **cận của bài toán cái túi phân số** (nhét tham lam + phần dư phân số), giúp quay lui cắt bỏ các nhánh không thể vượt qua kết quả tốt nhất hiện tại. Thứ tự món ban đầu được khôi phục trước khi in đáp án. |
| `TRR1_4003.cpp` | **Bài toán tìm đường đi Hamilton chi phí nhỏ nhất** (đi qua mọi đỉnh đúng một lần theo ma trận chi phí/khoảng cách; không có cạnh quay về điểm xuất phát). | Quay lui hoán vị các đỉnh chưa dùng vào `chosen[]`, cắt tỉa nhánh nào có chi phí bộ phận đã vượt kết quả tốt nhất hiện tại. |
| `TRR1_4004.cpp` | **Phiên bản tối đa hóa của `TRR1_4003.cpp`.** | Cùng cấu trúc quay lui, nhưng tối đa hóa tổng giá trị, không có cận cắt tỉa. |
| `TRR1_4007.cpp` | **Bài toán người bán hàng (TSP) — tìm chu trình Hamilton chi phí nhỏ nhất**, xuất phát và quay về đỉnh 1. | Cố định đỉnh xuất phát (`chosen[1] = 1`), quay lui trên mọi hoán vị của các đỉnh còn lại, cộng thêm cạnh quay về `mat[chosen[n]][1]` ở cuối, cắt tỉa khi chi phí hiện tại đã vượt kết quả tốt nhất. |
| `TRR1_4008.cpp` | **Bài toán phân công chi phí thời gian nhỏ nhất** (gán `n` vị trí theo ma trận thời gian `n×n`). | Quay lui tìm hoán vị không cố định đỉnh xuất phát; cắt tỉa khi thời gian hiện tại vượt kết quả tốt nhất. |
| `TRR1_4009.cpp` | **Phiên bản tối đa hóa của `TRR1_4008.cpp`, có tính sẵn cận cắt tỉa.** | Dùng mảng **suffix-max** (`suffMax[i]` = giá trị tốt nhất có thể đạt từ vị trí `i` trở đi, tức tổng các giá trị lớn nhất theo hàng) làm cận trên hợp lệ, cho phép cắt nhánh khi `currentVal + suffMax[pos] ≤ maxVal`. |
| `LT004.cpp` | **Chu trình Hamilton chi phí nhỏ nhất, in ra *tất cả* các chu trình tối ưu** (TSP có nhiều lời giải bằng nhau). | Quay lui giống `TRR1_4007.cpp`, nhưng thay vì chỉ giữ một kết quả tốt nhất, chương trình lưu lại **toàn bộ** các chu trình đạt chi phí nhỏ nhất vào `optimalPaths`, dùng cận cắt tỉa `currentCost + minCost*(số đỉnh còn lại) > currentMinCost`. In ra một chu trình duy nhất, hoặc số lượng cùng toàn bộ các chu trình bằng nhau. |
| `CODE/NDL.cpp` | **Chu trình Hamilton chi phí nhỏ nhất** (chỉ lấy một lời giải tốt nhất). | Ý tưởng giống `LT004.cpp`/`TRR1_4007.cpp` nhưng chỉ lưu một chi phí/đường đi tốt nhất duy nhất, dùng cùng kiểu cận cắt tỉa (`currentCost + số đỉnh còn lại * minCost ≥ currentMinCost`). |

## Bài toán công thức / lặt vặt khác

| File | Đề bài | Cách giải |
|---|---|---|
| `TRR1_5001.cpp` | **Công thức tính khả thi/đếm số lượng** với bốn tham số `h, m, n, t` (kiểu bài toán lịch trình/chuồng bồ câu — kiểm tra xem "vòng" thứ `t` có nằm trong giới hạn `h` hay không, dựa vào `m` và `n`). | Tính `res = (t-1)*m*n + 1`; nếu vượt quá `h` thì đáp án là `0`, ngược lại là `res`. |
| `TRR1_5005.cpp` | **Biến thể công thức** với `n, m, p`. Bộ chấm của CODEPTIT cho bài này bị lỗi — muốn được chấm đúng (AC) thì phải nộp code của `TRR1_5001.cpp` vào bài này. | Nếu `p > n`, in `1`; ngược lại in `(n-p)/m + (p==0 ? 0 : 1) + 1`. |

---

### Phần khung code dùng chung

Hầu hết các file đều bắt đầu bằng cùng một đoạn khung (chú thích tác giả, một bài thơ ngắn, và các macro):
```cpp
#define ll long long
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
```
`boost` giúp tắt đồng bộ giữa luồng C và C++ để nhập/xuất nhanh hơn — kỹ thuật phổ biến trong lập trình thi đấu. Một số biến toàn cục không dùng đến (`arr`, `k`, `a`, `b`, `x`, `y`, `l`, `r`, `MOD`) là phần còn sót lại từ khung code chung, không xuất hiện trong logic của mọi file.

### Lưu ý về các lỗi/đặc thù của hệ thống chấm
- `TRR1_5005.cpp`: Theo ghi chú trong file (tháng 7/2026), để được chấm đúng (AC) trên CODEPTIT với bài này cần nộp code của `TRR1_5001.cpp` thay vào.
- `TRR1_3024.cpp`: Đoạn code đang chạy thực chất là thuật toán sai nhưng vẫn qua được các test của CODEPTIT; một bản cài đặt đúng, đã kiểm chứng được đính kèm dưới dạng comment ngay phía dưới.
