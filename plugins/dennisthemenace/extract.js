function(page) {
    var regex = /<form name="safr".+<img src="([^"]*)"/;
    var match = regex.exec(page);
    return match[1]
}
