function(page) {
    var regex = /<img[^>]*src="([^"]*)" id="cc-comic"/;
    var match = regex.exec(page);
    return match[1];
}
