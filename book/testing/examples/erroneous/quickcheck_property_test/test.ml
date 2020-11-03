open Core_kernel

let%test_unit "negation flips the sign" =
  Quickcheck.test ~sexp_of:[%sexp_of: int]
    Int.quickcheck_generator
    ~f:(fun x ->
        [%test_eq: Sign.t]
          (Int.sign (Int.neg x))
          (Sign.flip (Int.sign x)))
