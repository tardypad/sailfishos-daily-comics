function(page) {
    var regex = /current-webcomic.*<img src="([^"]+)"/;
    var match = regex.exec(page);
    return match[1];
}
