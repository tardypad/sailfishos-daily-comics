function(page) {
    var regex = /<img[^>]*src="([^"]*)"[^>]*title="Cartoon des Tages[^"]*"/;
    var match = regex.exec(page);
    return match[1];
}
