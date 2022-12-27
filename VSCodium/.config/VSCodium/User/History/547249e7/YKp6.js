import react, { Component } from 'react';

class CarList extends Component {
    render() {
        const tableRows = this.state.cars.map((car, index) =>
            <tr key={index}>
                <td>{car.car_brand}</td>                
                <td>{car.car_brand}</td>                
                <td>{car.car_brand}</td>                
                <td>{car.car_brand}</td>                
                <td>{car.car_brand}</td>                
            </tr>
        );

        return (
             <div></div>
        );
    }
    
    constructor(props) {
        super(props);
        this.state = {cars : [] };
    }
    
    componentDidMount() {
        fetch('http://localhost:8080/api/cars')
        .then((response) => response.json())
        .then((responseData) => {
                this.setState({
                cars: responseData._embedded.cars,
            });
        })
        .catch(err => console.error(err));
    }
}

export default CarList;
