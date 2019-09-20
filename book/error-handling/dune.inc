(rule
 (target findlib.conf)
 (action (write-file %{target} "")))

(alias
 (name   runtest)
 (deps   (:x README.md)
         (:conf findlib.conf)
         (package mdx)
         (package base)
         (package core)
         (package ppx_jane)
         (:y2 examples/blow_up/blow_up.ml)
         (:y1 examples/exn_cost/exn_cost.ml)
         (:y0 examples/result.mli)
         (source_tree examples/blow_up)
         (source_tree examples/exn_cost)
         prelude.ml)
 (locks ../../global-lock)
 (action (progn
           (setenv OCAMLFIND_CONF %{conf} (run ocaml-mdx test --prelude=prelude.ml --direction=to-md %{x}))
           (diff? %{y2} %{y2}.corrected)
           (diff? %{y1} %{y1}.corrected)
           (diff? %{y0} %{y0}.corrected)
           (diff? %{x} %{x}.corrected))))
(alias
 (name   runtest-all)
 (deps   (:x README.md)
         (:conf findlib.conf)
         (package mdx)
         (package base)
         (package core)
         (package ppx_jane)
         (:y2 examples/blow_up/blow_up.ml)
         (:y1 examples/exn_cost/exn_cost.ml)
         (:y0 examples/result.mli)
         (source_tree examples/blow_up)
         (source_tree examples/exn_cost)
         prelude.ml)
 (locks ../../global-lock)
 (action (progn
           (setenv OCAMLFIND_CONF %{conf} (run ocaml-mdx test --prelude=prelude.ml --direction=to-md --non-deterministic %{x}))
           (diff? %{y2} %{y2}.corrected)
           (diff? %{y1} %{y1}.corrected)
           (diff? %{y0} %{y0}.corrected)
           (diff? %{x} %{x}.corrected))))