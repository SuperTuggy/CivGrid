# CivGrid v0.1 Extraction Spec

Goal:
Export drivable highways from OSM into GeoJSON.

Data Needed:

Nodes:
- id
- lat
- lon

Ways:
- id
- highway tag
- oneway tag
- ordered list of node IDs

Output:
- GeoJSON FeatureCollection
- Each feature = LineString
- Properties: highway type, oneway
