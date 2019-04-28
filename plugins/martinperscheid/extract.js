function(page) {
    var regex = /<div id="cartoon">[^]*?<img.*? src="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
