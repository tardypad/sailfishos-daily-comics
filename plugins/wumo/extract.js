function(page) {
    var regex = /<img[^>]*src="([^"]*\/img\/wumo\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
