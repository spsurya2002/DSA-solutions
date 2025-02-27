// Initialize the map
const map = L.map('map').setView([0, 0], 2);
L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    attribution: '© OpenStreetMap contributors'
}).addTo(map);

// Function to draw a curved arrow between two points
function drawCurvedArrow(source, destination, color) {
    // Calculate intermediate points for a curved path
    const midPoint = [
        (source[0] + destination[0]) / 2 + (Math.random() - 0.5) * 10, // Random curvature
        (source[1] + destination[1]) / 2 + (Math.random() - 0.5) * 10  // Random curvature
    ];

    // Create a curved path using Bezier curve
    const curvedPath = L.curve([
        'M', source,
        'Q', midPoint, destination
    ], {
        color: color, // Use the provided color
        weight: 2,
        opacity: 0.7,
        className: 'arrow-flow arrow-fade arrow-trail'
    }).addTo(map);

    // Add arrowhead
    if (L.polylineDecorator) {
        const arrowHead = L.polylineDecorator(curvedPath, {
            patterns: [
                { offset: '100%', repeat: 0, symbol: L.Symbol.arrowHead({ pixelSize: 10, polygon: false, pathOptions: { color: color } }) }
            ]
        }).addTo(map);
    } else {
        console.warn("L.polylineDecorator is not available. Curved arrows will be drawn without arrowheads.");
    }

    // Trigger fade-in effect
    setTimeout(() => {
        const arrowElement = curvedPath.getElement();
        if (arrowElement) {
            arrowElement.classList.add('visible');
        }
    }, 100);

    // Trigger trail effect
    const arrowElement = curvedPath.getElement();
    if (arrowElement) {
        arrowElement.style.strokeDasharray = '1000';
        arrowElement.style.strokeDashoffset = '1000';
        arrowElement.animate([
            { strokeDashoffset: 1000 },
            { strokeDashoffset: 0 }
        ], {
            duration: 2000,
            easing: 'linear'
        });
    }
}

// Fetch IP data from the Flask backend
async function fetchIPData() {
    const response = await fetch('/get_ip_data');
    const data = await response.json();
    return data;
}

// Update the map with new IP data
async function updateMap() {
    const ipPairs = await fetchIPData();

    // Clear previous markers and arrows
    map.eachLayer(layer => {
        if (layer instanceof L.Marker || layer instanceof L.Polyline) {
            map.removeLayer(layer);
        }
    });

    // Define colors for each pair
    const colors = ['red', 'blue', 'green', 'purple']; // 4 colors for 4 pairs

    // Add markers and arrows for each pair
    ipPairs.forEach((pair, index) => {
        const source = [pair.source.lat, pair.source.lon];
        const destination = [pair.destination.lat, pair.destination.lon];
        const color = colors[index % colors.length];

        // Add markers for source and destination
        L.marker(source, {
            className: 'marker-pulse marker-rotate' // Add rotating effect
        }).addTo(map).bindPopup(`Source: ${pair.source.city}, ${pair.source.state}, ${pair.source.country}`);

        L.marker(destination, {
            className: 'marker-pulse marker-rotate' // Add rotating effect
        }).addTo(map).bindPopup(`Destination: ${pair.destination.city}, ${pair.destination.state}, ${pair.destination.country}`);

        // Draw a curved arrow between source and destination
        drawCurvedArrow(source, destination, color);
    });
}

// Update the map every 2 seconds
setInterval(updateMap, 2000);

// Initial map update
updateMap();
