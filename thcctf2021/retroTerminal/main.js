!function() {
    function e(e) {
        return function(e) {
            if (Array.isArray(e))
                return t(e)
        }(e) || function(e) {
            if ("undefined" != typeof Symbol && Symbol.iterator in Object(e))
                return Array.from(e)
        }(e) || function(e, n) {
            if (!e)
                return;
            if ("string" == typeof e)
                return t(e, n);
            var r = Object.prototype.toString.call(e).slice(8, -1);
            "Object" === r && e.constructor && (r = e.constructor.name);
            if ("Map" === r || "Set" === r)
                return Array.from(e);
            if ("Arguments" === r || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(r))
                return t(e, n)
        }(e) || function() {
            throw new TypeError("Invalid attempt to spread non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method.")
        }()
    }
    function t(e, t) {
        (null == t || t > e.length) && (t = e.length);
        for (var n = 0, r = new Array(t); n < t; n++)
            r[n] = e[n];
        return r
    }
    var n, r = document.querySelector.bind(document), i = r(".splash-title"), o = r(".splash-title > .words"), a = r("#countdown-value");
    document.body.style.setProperty("--splash-scale", window.innerHeight / i.offsetHeight),
    document.body.style.setProperty("--splash-translateY", window.innerHeight / 2 - function e(t, n) {
        return t[n] + (t.offsetParent ? e(t.offsetParent, n) : 0)
    }(i, "offsetTop") - i.offsetHeight / 2),
    document.body.style.setProperty("--splash-translateX", o.offsetWidth),
    window.scrollY <= 1 && 0 === window.location.hash.length && document.body.classList.add("-do-splash"),
    (n = function() {
        requestAnimationFrame((function() {
            return document.body.style.setProperty("--scroll", (window.scrollY / window.innerHeight).toString())
        }
        ), 0)
    }
    )(),
    window.addEventListener("scroll", (function(e) {
        return n()
    }
    ), {
        passive: !0
    }),
    function e() {
        var t = new Date("2021-06-11T11:00:00.000Z") - new Date;
        if (t < 0)
            a.innerHTML = "0!!";
        else {
            var n = (t / 864e5).toFixed(5);
            a.innerHTML !== n && (a.innerHTML = n),
            requestAnimationFrame(e)
        }
    }(),
    function() {
        var t = {
            newline: 100,
            interrupt: 1e3,
            typed: 50
        }
          , n = r("#splash-console > pre > code");
        r("#f").innerHTML = atob("VEhDb24yMXt1bmRlci15b3VyLW5vc2V9").replace(/./g, "*");
        var i, o, a = e(n.childNodes).map((function(e) {
            if (e instanceof Text)
                return {
                    type: "raw",
                    value: e.wholeText
                };
            if ("I" === e.tagName)
                return {
                    type: "interrupt"
                };
            if ("S" === e.tagName)
                return {
                    type: "typed",
                    value: e.innerText
                };
            if ("BR" === e.tagName)
                return {
                    type: "newline"
                };
            throw new Error("Unknown tag: " + e.tagName)
        }
        ));
        i = "flag.txt",
        o = "There's a flag here?!",
        a.push({
            type: "raw",
            value: "root@thcon.party:~$ "
        }, {
            type: "interrupt"
        }, {
            type: "interrupt"
        }, {
            type: "typed",
            value: "cat " + i
        }, {
            type: "newline"
        }, {
            type: "interrupt"
        }),
        o.replace(/(.{80})/g, "$1\n").split("\n").forEach((function(e) {
            a.push({
                type: "raw",
                value: e
            }, {
                type: "newline"
            })
        }
        )),
        a.push({
            type: "newline"
        }, {
            type: "interrupt"
        }),
        a.push({
            type: "raw",
            value: "root@thcon.party:~$ "
        }, {
            type: "interrupt"
        }, {
            type: "interrupt"
        }, {
            type: "typed",
            value: "Interested in the CTF? Keep reading this page ;)"
        }, {
            type: "interrupt"
        }, {
            type: "raw",
            value: "^C"
        }, {
            type: "newline"
        }, {
            type: "newline"
        }, {
            type: "raw",
            value: "root@thcon.party:~$ "
        }),
        n.innerHTML = "";
        var u = function(e) {
            n.innerText += e
        };
        !function e() {
            if (0 !== a.length) {
                var n = a[0];
                if ("raw" === n.type)
                    u(n.value),
                    a.shift(),
                    e();
                else if ("interrupt" === n.type || "newline" === n.type)
                    "newline" === n.type && u("\n"),
                    a.shift(),
                    setTimeout(e, t[n.type]);
                else if ("typed" === n.type) {
                    if ("" === n.value)
                        return a.shift(),
                        void e();
                    u(n.value[0]),
                    n.value = n.value.substring(1),
                    setTimeout(e, t.typed)
                }
            }
        }()
    }()
}();
