function(page) {
    var regex = /<div id="comic">[^]*?<img.*?src="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
