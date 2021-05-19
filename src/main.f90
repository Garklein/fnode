function hello() bind (c, name="hello") result(ptr)
    use iso_c_binding
    implicit none
    type(c_ptr) :: ptr
    character(len=20), save, target :: msg

    msg = "Hello from Fortran!" // c_null_char
    ptr = c_loc(msg)
end function hello

real(kind=8) function add(a, b) bind (c, name="add") result(sum)
    use iso_c_binding
    implicit none
    real(kind=8), intent(in) :: a, b
    sum = a + b
end function add