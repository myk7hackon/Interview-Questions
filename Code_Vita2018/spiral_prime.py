def nth_prime_number(n):
    prime_list = [2]
    num = 3
    while len(prime_list) < n:
        for p in prime_list:
            if num % p == 0:
                break
        else:
            prime_list.append(num)
        num += 2
    return prime_list[-1]

def return_val(x,y):
    if abs(x)>abs(y):
        if x>0:
            return(4*x*x-3*x+y)
        else:
            return (4*x*x-x-y)
    else:
        if y>0:
            return (4*y*y-y-x)
        else:
            return (4*y*y-3*y+x)

n=int(input())
for i in range(n):
    input_str=input()
    x,y=input_str.split(',')
    x=int(x);y=int(y)
    val=return_val(x,y)+1
    ans_val=nth_prime_number(val)
    print(ans_val,end='')