type t(+'a);
type error = exn;

[@bs.module] [@bs.new]
external mk :
    ((~resolve: ('a => unit), ~reject: (exn => unit)) => unit)
    => t('a) = "bluebird";

/* For compatibility with Js.Promise interface */
[@bs.module] [@bs.new]
external make :
    ((~resolve: (. 'a) => unit, ~reject: (. exn) => unit) => unit)
    => t('a) = "bluebird";

external toJs : t('a) => Js.Promise.t('a) = "%identity";
[@bs.module "bluebird"] external fromJs : Js.Promise.t('a) => t('a) = "resolve";

[@bs.module "bluebird"] external resolve : 'a => t('a) = "";
[@bs.module "bluebird"] external reject : exn => t('a) = "";

[@bs.module "bluebird"] external all : array(t('a)) => t(array('a)) = "";
[@bs.module "bluebird"] external all2 : ((t('a), t('b))) => t(('a, 'b)) = "all";
[@bs.module "bluebird"] external all3 : ((t('a), t('b), t('c))) => t(('a, 'b, 'c)) = "all";
[@bs.module "bluebird"] external all4 : ((t('a), t('b), t('c), t('d))) => t(('a, 'b, 'c, 'd)) = "all";
[@bs.module "bluebird"] external all5 : ((t('a), t('b), t('c), t('d), t('e))) => t(('a, 'b, 'c, 'd, 'e)) = "all";
[@bs.module "bluebird"] external all6 : ((t('a), t('b), t('c), t('d), t('e), t('f))) => t(('a, 'b, 'c, 'd, 'e, 'f)) = "all";

[@bs.module "bluebird"] external race : array(t('a)) => t('a) = "";

[@bs.send.pipe: t('a)] external then_ : ('a => t('b)) => t('b) = "then";
[@bs.send.pipe: t('a)] external catch : (error => t('a)) => t('a) = "";

[@bs.send.pipe: t(('a, 'b))] external spread2 : ('a => 'b => t('c)) => t('c) = "spread";

[@bs.send.pipe: t('a)] external isFulfilled : bool = "";
[@bs.send.pipe: t('a)] external isRejected : bool = "";
[@bs.send.pipe: t('a)] external isPending : bool = "";
[@bs.send.pipe: t('a)] external isCancelled : bool = "";
