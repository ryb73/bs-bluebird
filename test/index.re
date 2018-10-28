open Bluebird;

let map = (callback) => then_((v) => resolve(callback(v)));

mk
    ((~resolve, ~reject as _) => {
        resolve(12);
    })
    |> then_((n) => {
        Js.log2("it's", n);
        /* Js.Exn.raiseError("nooo"); */
        resolve();
    })
    |> catch((exn) => {
        Js.log2("error", exn);
        resolve();
    });

make
    ((~resolve, ~reject as _) => {
        resolve(. 12);
    })
    |> then_((n) => {
        Js.log2("it's", n);
        resolve();
    })
    |> catch((exn) => {
        Js.log2("error", exn);
        resolve();
    });

all([| resolve(1), resolve(2), resolve(3) |])
    |> map(Js.log);

all2((resolve(99), resolve("problems")))
    |> spread2((a, b) => {
        Js.log2(a, b);
        resolve();
    });

Js.Promise.resolve(("a", "b"))
    |> fromJs
    |> spread2((a, b) => {
        Js.log2(a, b);
        resolve();
    });
