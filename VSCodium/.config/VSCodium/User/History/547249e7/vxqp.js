import react, { Component } from 'react';

class CarList extends Component {
    render() {
        const tableRows = this.state.cars.map((car, index) =>
            <tr key={index}>
                <td>{car.car_brand}</td>                
                <td>{car.car_model}</td>                
                <td>{car.car_year}</td>                
                <td>{car.car_price}</td>                
                <td>{car.car_color}</td>                
            </tr>
        );

        return (
             <div className="App">
                <table>
                    <tbody>{tableRows}</tbody>
                </table>
             </div>
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
